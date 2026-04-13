# Create a Simulator object
set ns [new Simulator]

# Define different colors for data flows (TCP=Blue, UDP=Red)
$ns color 1 Blue
$ns color 2 Red

# Open the Trace file and NAM file
set tracefile1 [open out.tr w]
$ns trace-all $tracefile1
set namfile [open out.nam w]
$ns namtrace-all $namfile

# Open a file to record TCP Window size
set winfile [open winfile w]

# Define the 'finish' procedure
proc finish {} {
    global ns tracefile1 namfile
    $ns flush-trace
    close $tracefile1
    close $namfile
    # Execute NAM to see the visualization
    exec nam out.nam &
    exit 0
}

# Create six nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

# Optional: Change node appearance
$n1 color Red
$n1 shape box

# Create point-to-point links
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail

# SET UP THE LAN (Connecting n3, n4, n5)
# Parameters: Nodes, Bandwidth, Delay, LL, Queue, MAC, Channel
set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd Channel]

# Define visual layout for NAM
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns simplex-link-op $n2 $n3 orient right
$ns simplex-link-op $n3 $n2 orient left

# Set Queue limit for the bottleneck link
$ns queue-limit $n2 $n3 20

# Setup TCP Connection (n0 to n4)
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

# Setup FTP application over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp

# Setup UDP Connection (n1 to n5)
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp $null
$udp set fid_ 2

# Setup CBR (Constant Bit Rate) over UDP
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packet_size_ 1000
$cbr set rate_ 0.01Mb

# Procedure to plot the Congestion Window
proc plotWindow {tcpSource file} {
    global ns
    set time 0.1
    set now [$ns now]
    set cwnd [$tcpSource set cwnd_]
    puts $file "$now $cwnd"
    $ns at [expr $now+$time] "plotWindow $tcpSource $file"
}

# Schedule Events
$ns at 0.1 "plotWindow $tcp $winfile"
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 124.0 "$ftp stop"
$ns at 125.5 "$cbr stop"
$ns at 125.0 "finish"

# Run the simulation
$ns run