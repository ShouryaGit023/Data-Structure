set ns [new Simulator]

# Define colors for flows
$ns color 1 Blue
$ns color 2 red

# Open Trace and NAM files
set file1 [open out.tr w]
set winfile [open Winfile w]
$ns trace-all $file1
set file2 [open out.nam w]
$ns namtrace-all $file2

proc finish {} {
    global ns file1 file2
    $ns flush-trace
    close $file1
    close $file2
    exec nam out.nam &
    exit 0
}

# Create 6 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$n1 color Red
$n1 shape box

# Create links
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail

# KEY CHANGE: MAC/Csma/Ca instead of MAC/Csma/Cd
set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Ca Channel]

# TCP Setup
set tcp [new Agent/TCP/Newreno]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 552

set ftp [new Application/FTP]
$ftp attach-agent $tcp

# UDP Setup
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packet_size_ 1000
$cbr set rate_ 0.01mb
$cbr set random_ false

# Window Plotting Procedure
proc plotWindow {tcpSource file} {
    global ns
    set time 0.1
    set now [$ns now]
    set cwnd [$tcpSource set cwnd_]
    puts $file "$now $cwnd"
    $ns at [expr $now+$time] "plotWindow $tcpSource $file"
}

# Scheduling
$ns at 0.1 "plotWindow $tcp $winfile"
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 123.0 "$ftp stop"
$ns at 124.5 "$cbr stop"
$ns at 5 "$ns trace-annotate \"packet drop\""
$ns at 125.0 "finish"

$ns run