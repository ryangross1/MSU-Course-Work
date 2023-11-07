import socket
import sys
import random

def generateBoard():
    board = [['O']*6 for i in range(6)]

    for size in range(2, 5):
        valid = False

        while not valid:
            dir = random.random()
            # For horizontal orientation
            if (dir == 0):
                row = random.Random(6)
                pass



            # For vertical orientation
            elif (dir == 1):
                pass


    # board = [['O', 'O', 'O', 'O', '*', 'O'],
    #          ['O', '*', 'O', 'O', '*', 'O'],
    #          ['O', '*', 'O', 'O', 'O', 'O'],
    #          ['O', '*', 'O', 'O', 'O', 'O'],
    #          ['O', 'O', 'O', 'O', 'O', 'O'],
    #          ['O', 'O', '*', '*', '*', '*']]
    return board

def receiveGuess(guessNum):
    return
    
# def main():
game = generateBoard()

port = int(sys.argv[1])
host = socket.gethostname()

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind( (host, port) )

print("Ready for connection on port", port)

serverSocket.listen(1)

conn, addr = serverSocket.accept()

while True:
    row = int(conn.recv(1024).decode())
    col = int(conn.recv(1024).decode())

    if (game[row][col] == '*'):
        conn.send("HIT".encode())
    else:
        conn.send("MISS".encode())

    # if (row != None and col != None):
        # coord = str("We recieved" + row + "and" + col)
        # print("row:", row, "column:", col)
