# Create a simulator object
set ns [new Simulator]

# Open the output trace file for XGraph
set f0 [open out0.tr w]

# Create 2 nodes
set n0 [$ns node]
set n1 [$ns node]

# Connect the nodes using duplex link
$ns duplex-link $n0 $n1 1Mb 100ms DropTail

# Setup a UDP connection (The source of our traffic)
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

# Create the LossMonitor sink to track bytes
set sink0 [new Agent/LossMonitor]
$ns attach-agent $n1 $sink0

# Connect the traffic source to the sink
$ns connect $udp $sink0

# Setup CBR (Constant Bit Rate) to generate 0.8Mb of traffic
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 0.8Mb
$cbr set random_ false

# Define a 'finish' procedure
proc finish {} {
    global f0
    close $f0
    # Call xgraph to display the results
    puts "Opening XGraph..."
    exec xgraph out0.tr -geometry 800x400 &
    exit 0
}

# Procedure to periodically record the bandwidth
proc record {} {
    global sink0 f0
    set ns [Simulator instance]
    
    # Sampling interval (0.5 seconds)
    set time 0.5
    
    # Get bytes received by the LossMonitor
    set bw0 [$sink0 set bytes_]
    set now [$ns now]
    
    # Calculate Bandwidth in Mbps: (Bytes * 8) / (Time * 10^6)
    set val [expr $bw0/$time*8/1000000]
    
    # Write to file: Time <space> Value
    puts $f0 "$now $val"
    
    # Reset the bytes_ counter for the next interval
    $sink0 set bytes_ 0
    
    # Re-schedule the procedure
    $ns at [expr $now+$time] "record"
}

# Schedule events
$ns at 0.0 "record"
$ns at 0.5 "$cbr start"
$ns at 59.5 "$cbr stop"
$ns at 60.0 "finish"

# Run the simulation
$ns run