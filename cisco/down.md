# NS-2 Installation Guide

## Step 1: Update and Install Prerequisite Packages

Run the following commands to update your system and install required dependencies:

```bash
sudo apt-get update
sudo apt-get dist-upgrade
sudo apt-get install gcc build-essential autoconf automake
sudo apt-get install tcl8.5-dev tk8.5-dev
sudo apt-get install perl xgraph libxt-dev libx11-dev libxmu-dev
```

## Step 2: Download NS-2

Download the `ns-allinone-2.35.tar.gz` file from the official source.

## Step 3: Extract the Archive

Right-click on the downloaded file and select **Extract Here** to extract its contents.

## Step 4: Navigate to the Extracted Directory

```bash
cd ns-allinone-2.35
```

## Step 5: Run the Installation Script

```bash
./install
```

## Step 6: Configure Environment Variables

1. Open the `.bashrc` file:
   ```bash
   sudo gedit ~/.bashrc
   ```

2. Add the following configuration to the file:

```bash
# LD_LIBRARY_PATH
export OTCL_LIB=/your/path/ns-allinone-2.35/otcl-1.14
export NS2_LIB=/your/path/ns-allinone-2.35/lib
export X11_LIB=/usr/X11R6/lib
export USR_LOCAL_LIB=/usr/local/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$OTCL_LIB:$NS2_LIB:$X11_LIB:$USR_LOCAL_LIB

# TCL_LIBRARY
export TCL_LIB=/your/path/ns-allinone-2.35/tcl8.5.10/library
export USR_LIB=/usr/lib
export TCL_LIBRARY=$TCL_LIB:$USR_LIB

# PATH
export XGRAPH=/your/path/ns-allinone-2.35/bin:/your/path/ns-allinone-2.35/tcl8.5.10/unix:/your/path/ns-allinone-2.35/tk8.5.10/unix
export NS=/your/path/ns-allinone-2.35/ns-2.35/
export NAM=/your/path/ns-allinone-2.35/nam-1.15/
export PATH=$PATH:$XGRAPH:$NS:$NAM
```

3. Save the file and reboot your system.

## Verification

After rebooting, run the following command to verify the installation:

```bash
ns
```

If NS-2 is correctly installed, you should see the `%` prompt, indicating successful installation.

**Note:** Replace `/your/path/` with the actual path where you extracted `ns-allinone-2.35`.