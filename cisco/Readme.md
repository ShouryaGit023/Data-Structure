# Experiment 10: Local Area Network (LAN) Simulation

## 📌 Objective
To simulate a Local Area Network (LAN) using NS-2, implementing various network topologies and analyzing the behavior of TCP and UDP traffic over a shared medium.

---

## 🛠️ Prerequisites
* **Simulator:** NS-2 (Network Simulator 2)
* **Visualization:** NAM (Network Animator)
* **OS:** Ubuntu / Linux
* **Scripting:** OTcl (Object Tcl)

---

## 📂 Files Overview
| File | Description |
| :--- | :--- |
| `lan.tcl` | The simulation script containing topology and traffic definitions. |
| `out.tr` | **Trace File:** Stores raw data of every packet event (Send, Receive, Drop). |
| `out.nam` | **NAM File:** Stores animation data for visual representation. |
| `winfile` | **Window File:** Logs the TCP Congestion Window (cwnd) values. |

---

## 🚀 Execution Steps

### 1. Create the Script
Open your terminal and create the Tcl script:
```bash
gedit lan.tcl
(Paste the simulation code and save the file.)

2. Run the Simulation
Execute the script using the ns interpreter:

Bash
ns lan.tcl
3. Visualize the Network
The script is configured to open NAM automatically.

Click the Play button in the top left.

Observe the Blue (TCP) and Red (UDP) flows.

Watch how packets interact at the bottleneck link (n2-n3) and the LAN (n3-n4-n5).

4. Data Analysis (Optional)
To check the number of packets dropped in the trace file:

Bash
grep "^d" out.tr | wc -l
📐 Network Configuration
Nodes: 6 Nodes (n0 to n5).

Point-to-Point: Duplex links between n0-n2 and n1-n2.

Bottleneck: Simplex link between n2 and n3 (0.3Mb bandwidth).

LAN Topology: Shared medium connecting nodes n3, n4, and n5 using CSMA/CD.

Traffic: - FTP over TCP (Node 0 to Node 4)

CBR over UDP (Node 1 to Node 5)

💡 Troubleshooting
Path Error: If ns command is not found, run source ~/.bashrc.

NAM crash: Ensure your finish procedure includes exec nam out.nam & and ends with exit 0.


---

### Final Check for your Viva:
* **The "Finish" Proc:** Make sure you mention that `flush-trace` is crucial because it writes the remaining data in the buffer to the file before closing.
* **CSMA/CD:** If asked why the LAN nodes don't collide constantly, explain that **CSMA/CD** (Carrier Sense Multiple Access with Collision Detection) allows nodes to "listen" before they "talk."

**Go get 'em, Shourya! Let me know how the practical goes.**


```
### exp 11

# Experiment 11: Implementation of Various MAC Protocols (CSMA/CA)

## 📌 Objective
To implement and study the performance of the **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** MAC protocol in a simulated network environment using NS-2.

---

## 🛠️ Prerequisites
* **Simulator:** NS-2 (Network Simulator 2)
* **Visualization:** NAM (Network Animator)
* **Language:** OTcl (Object Tcl)
* **Environment:** Ubuntu/Linux

---

## 📂 Files Generated
| File Name | Purpose |
| :--- | :--- |
| `csma.tcl` | The simulation script defining the nodes and the CSMA/CA LAN. |
| `out.tr` | **Trace File:** Records every packet event for performance analysis. |
| `out.nam` | **NAM File:** The animation data used by the Network Animator. |
| `Winfile` | **Window Log:** Records the TCP Congestion Window size over time. |

---

## 🚀 Execution Guide

### 1. File Preparation
Create the script file in your terminal:
```bash
gedit csma.tcl
(Paste the Experiment 11 code provided in the manual, save, and exit.)

2. Running the Simulation
Execute the script through the ns interpreter:

Bash
ns csma.tcl
3. Analyzing the Output
NAM Visualization: The Network Animator will open automatically. Press Play to observe how the CSMA/CA mechanism handles packet transmission on the shared LAN (Nodes 3, 4, and 5).

Trace Annotation: At simulation time 5.0, look for the text label "packet drop" in the NAM window to see where congestion begins.

Congestion Window: Open Winfile to see the numerical data of how TCP Newreno scales its transmission speed.

🏗️ Topology Configuration
Point-to-Point Links: n0-n2 and n1-n2 (2Mb, 10ms).

Bottleneck Link: n2-n3 (0.3Mb, 100ms) — this creates the congestion needed to study MAC performance.

LAN Segment: n3, n4, and n5 connected via MAC/Csma/Ca.

Traffic Flows: - TCP (Blue): FTP traffic from n0 to n4.

UDP (Red): CBR traffic from n1 to n5.

💡 Key Differences to Note (Viva Prep)
Collision Avoidance: Unlike CSMA/CD (which detects collisions), CSMA/CA tries to avoid them using a random back-off timer before transmitting.

Efficiency: CSMA/CA is essential for wireless environments where nodes cannot detect collisions while transmitting.


### 💡 Quick Viva Refresher for Exp 11:


* **RTS/CTS:** In many CSMA/CA implementations, nodes use **Request to Send** and **Clear to Send** signals to "reserve" the medium.
* **Inter-Frame Spacing (IFS):** This is the mandatory wait time between transmissions in CSMA/CA to ensure the medium is truly clear.

**Good luck with your CN practical, Shourya! You've got all the code



```
### 12. throughput
# Experiment 12: Network Performance Visualization (XGraph)

## 📌 Objective
To monitor and plot the real-time throughput of a duplex wired link using NS-2 and the XGraph utility.

---

## 🚀 Execution Steps
1. **Save the code:** Create a file named `perf.tcl`.
2. **Run the simulation:** ```bash
   ns perf.tcl
Observation: The simulation will run for 60 seconds (virtual time). Upon completion, a window will pop up displaying the throughput graph.

📐 Parameters
Bandwidth: 1 Mb

Delay: 100 ms

Sampling Interval: 0.5 seconds

Output Unit: Megabits per second (Mbps)

💡 Key Terms for Viva
Throughput: The actual rate of successful message delivery.

XGraph: A plotting tool that reads space-separated values (X Y) from a file.

Recursive Procedure: The record proc calls itself using $ns at [expr $now+$time] "record".