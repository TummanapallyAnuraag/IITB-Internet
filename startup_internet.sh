#!/usr/bin/env bash
enc_password="Put Base64 aEncoded Pasword Here"
password=$(eval echo ${enc_password} | base64 --decode)
curl -d "uname=??????????&passwd=$password" https://internet.iitb.ac.in/index.php
