#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from socket import*

def sendVal(x):
    
    server_address = "192.168.31.71"
    server_port = 8888
    
    client_sock = socket(AF_INET,SOCK_STREAM)
    client_sock.connect((server_address,server_port))
    
    r =str(x)
    
    
    value = r
    
    message = value
    client_sock.send(message.encode())
    
    
    
    
    client_sock.close()

while True:
    a=input("Enter Direction")
    sendVal(a)
    
