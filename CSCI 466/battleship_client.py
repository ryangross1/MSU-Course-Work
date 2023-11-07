import socket
import sys

# rows, cols = (6, 6)
hitCount = 0
client_arr = [['?']*6 for i in range(6)]
for r in client_arr:
    print(r)


def guess(clientSocket):
    guess_row = int(input("Enter number for 1-6 for row: ")) - 1
    guess_col = int(input("Enter number for 1-6 for column: ")) - 1
    clientSocket.send(str(guess_row).encode())
    clientSocket.send(str(guess_col).encode())
    hit = clientSocket.recv(1024).decode()
    return clientBoard(guess_row, guess_col, hit)

def clientBoard(row, col, hit):
    numHits = 0
    if hit == 'HIT':
        client_arr[row].pop(col)
        client_arr[row].insert(col, 'X')
        # hitCount += 1
    elif hit == 'MISS':
        client_arr[row].pop(col)
        client_arr[row].insert(col, 'O')

    for r in client_arr:
        print(r)
        for c in r:
            if (c == 'X'):
                numHits += 1
                
    print(hit)

    return numHits


# def main():
port = int(sys.argv[1])
win = False
host = socket.gethostname()

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect( (host, port) )

numGuesses = 0

while win != True:
    numGuesses += 1
    hitCount = guess(clientSocket)
    if hitCount == 9:
        win = True
        
print("You won in", numGuesses, "guesses!")
