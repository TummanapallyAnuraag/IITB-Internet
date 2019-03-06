# IITB-Internet
Internet Connection Script(s) for internet.iitb.ac.in

# Usage

## Linux
* C Executable
```
cd IITB-Internet/Unix
chmod +x connect_internet
./connect_internet
```
* Unix Shell Script

Paste Base64 encoded password, and username in `startup_internet.sh`
```
cd IITB-Internet/Unix
chmod 711 startup_internet.sh
./startup_internet.sh
```

Once this works, add the script to System Startup Applications.

## Windows


# Files
<pre>
.
|-- Unix
|   |-- connect_internet
|   |-- iitb-internet-access.c
|   `-- startup_internet.sh
|-- Windows
|-- guipic.png
`-- README.md
</pre>

# Dependencies
Required libraries: `curl`, `ncurses`

Compilation: `gcc iitb-internet-access.c -o connect_internet -lncurses -lcurl`

# GUI
![GUI Preview][guipic]

[guipic]:guipic.png "Terminal Screenshot!"
