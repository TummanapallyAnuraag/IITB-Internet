# IITB-Internet
Internet Connection Script(s) for internet.iitb.ac.in

# Usage
```
cd IIT-Internet/Unix
chmod +x connect_internet
./connect_internet
```

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
