import socket
import sys
import random

def generateBoard():
    board = [['O']*6 for i in range(6)]

    for size in range(2, 5):
        move_found = False

        while not move_found:
            dir = random.randint(0, 1)
            valid_move = True

            # For horizontal orientation
            if (dir == 0):
                row = random.randint(0, 5)
                col = random.randint(0, 6 - size)

                for check in range(col, col + size):
                    if (board[row][check] == '*'):
                        valid_move = False
                        break
                
                if valid_move:
                    move_found = True
                    for c in range(col, col + size):
                        board[row][c] = '*'

            # For vertical orientation
            elif (dir == 1):
                row = random.randint(0, 6 - size)
                col = random.randint(0, 5)

                for check in range(row, row + size):
                    if (board[check][col] == '*'):
                        valid_move = False
                        break
                
                if valid_move:
                    move_found = True
                    for r in range(row, row + size):
                        board[r][col] = '*'
    return board

game = generateBoard()
for r in game:
    print(r)

port = int(sys.argv[1])
host = socket.gethostname()

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind( (host, port) )

print("Ready for connection on port", port)

serverSocket.listen(1)

conn, addr = serverSocket.accept()

game_active = True
hits = 0

while game_active:
    row = int(conn.recv(1024).decode())
    col = int(conn.recv(1024).decode())

    if (game[row][col] == '*'):
        hits += 1
        conn.send("HIT".encode())
        if (hits == 9):
            game_active = False
    else:
        conn.send("MISS".encode())