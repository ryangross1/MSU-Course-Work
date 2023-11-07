# server program

import socket
import random

print("Server is starting")
port = 9000
host = socket.gethostname()

# bind socket
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #TCP socket
serverSocket.bind( (host, port) )

rand_num = random.randint(1, 10)

print("Server is ready for connections")

serverSocket.listen(1)

#accept new connection(s)
connection, addr = serverSocket.accept()

# message = connection.recv(1024).decode()
# print("The message is, ", message)

while True:

    user_guess = int(connection.recv(1024).decode())

    if (user_guess > rand_num) :
        connection.send("Lower".encode())
    elif (user_guess < rand_num) :
        connection.send("Higher".encode())
    else:
        connection.send("Win!".encode())
        break

