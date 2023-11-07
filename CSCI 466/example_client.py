# client program

import socket

port = 9000
host = socket.gethostname()

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect( (host, port) )

#clientSocket.send("hi".encode())

hasSolved = False

while (not hasSolved):
    user_guess = input("Enter a number 1-10")
    clientSocket.send(user_guess.encode())
    response = clientSocket.recv(1024).decode()
    print(response)
    if (response == "Win!"): 
        hasSolved = True
    
print("You Win")