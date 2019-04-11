# IITB-Internet
Internet Connection Script(s) for internet.iitb.ac.in

## List of Other Repositories to solve the same Problem:
* [Python Script for terminal login/logout to internet.iitb.ac.in](https://github.com/sumeetfefar/iitb-internet-login)
* [This extension will automatically login into internet.iitb.ac.in page whenever chrome is opened.](https://github.com/nihal111/IITB-login-extension-Chrome)
* [App Indicator to login into internet.iitb.ac.in for Linux Systems ](https://github.com/anshulgupta0803/iitb-internet-login)
* [Log on to internet.iitb.ac.in with one click ](https://github.com/akshitt/auto-login)
* [A Simple App that will automatically log in to internet.iitb.ac.in ... ](https://github.com/saqib1707/fastStartup)

# Usage

## Windows

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

* Shell Script
```
ITB-Internet/Unix
chmod +x shell_script.sh
./shell_script.sh
```

# Files
<pre>
.
|-- Unix
|   |-- connect_internet
|   |-- iitb-internet-access.c
|   |-- shell_script.sh
|   `-- startup_script.sh

|-- Windows
|-- guipic.png
`-- README.md
</pre>

# Dependencies
Required libraries: `curl`, `ncurses`

Compilation: `gcc iitb-internet-access.c -o connect_internet -lncurses -lcurl`

# GUI

* For C Biinary (`./connect_internet`)

![GUI Preview][guipic1]

* For Shell Script (`./shell_script.sh`)

![GUI Preview][guipic2]

[guipic1]:guipic.png "Terminal Screenshot!"
[guipic2]:guipic2.png "Terminal Screenshot!"
