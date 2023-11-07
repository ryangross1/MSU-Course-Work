import socket
import sys
import random
import pickle
import time

class Packet:
    def __init__(self, seq, checksum, ack_or_nak, len, message):
        self.seq = seq
        self.checksum = checksum # can also be a string or boolean ("valid" or "invalid")
        self.ack_or_nak = ack_or_nak # ack = 1, nak=0, neither = 2
        self.len = len
        self.message = message
    def __str__(self):
        return f"{self.seq}, {self.checksum}, {self.ack_or_nak}, {self.len}, {self.message}" 

    
def checksum_bool(probability):
    return random.random() > probability

def translate(msg):
    punc = msg[-1]
    d = {}  #create dictionary
    file = open('pirate.csv', 'r')
    for l in file:  #fill dictionary
        split = l.split(",")
        d[split[0]] = split[1].strip("\n") #english key, pirate value
    
    pirate_str = ""
    msg = msg.strip(punc)
    words = msg.split(" ")
    for w in words:
        if w in d:
            pirate_str += d[w]
            pirate_str += " "
        else:
            pirate_str += w
            pirate_str += " "
    
    pirate_str = pirate_str.strip(" ")
    pirate_str += punc
    print(pirate_str)
    return(pirate_str)


port = int(sys.argv[1])
size = int(sys.argv[2])
corrupt_prob = float(sys.argv[3])

host = socket.gethostname()

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind( (host, port) )

print("Ready for connection on port", port)
serverSocket.listen(1)

conn, addr = serverSocket.accept()
# while loop for receiving strings from client

packets = []

# While loop for receiving segmented user input, 
# and sending ACKs back
done = False
while not done:
    pac = pickle.loads(conn.recv(1024))
    print(pac)
    if pac.checksum == True:            # if received packet valid
        if (len(packets) > 0) and (packets[-1].seq == pac.seq):     # checks if previous packet matches current one (retransmission)
            pass
        else:
            packets.append(pac)     # replace with new packet if true
        

        if pac.message.endswith(".") or pac.message.endswith("?") or pac.message.endswith("!"):
            reply = Packet(0, True, 1, 0, "")   # create ACK response
            conn.send(pickle.dumps(reply))
            done = True
        else:
            checksum = checksum_bool(corrupt_prob)
            reply = Packet(0, checksum, 1, 0, "")   # create ACK response
            conn.send(pickle.dumps(reply))

    elif pac.checksum == False:         # if recieved packet is invalid
        reply = Packet(0, True, 0, 0, "")       #create NAK response
        conn.send(pickle.dumps(reply))

full_string = ""
for pack in packets:
    full_string += pack.message

print(full_string)

#Function for translating received message to pirate
pirate_str = translate(full_string)


serverSocket.close()


host = socket.gethostname()

serverSocket2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket2.connect( (host, port) )


print("Ready for reconnection on port", port)
segmented_message = [pirate_str[i:i+size] for i in range(0, len(pirate_str), size)]
# # While loop for sending segmented translated pirate message back, 
# # and receiving ACKs from client
# pirate_str = "That boy is me hearty."
#print(segmented_message) #TEST
idx = 0
while idx < len(segmented_message):
    pac = Packet(idx+1, checksum_bool(corrupt_prob), 2, len(segmented_message[idx]), segmented_message[idx])
    serverSocket2.send(pickle.dumps(pac))
    time.sleep(1)
    response = pickle.loads(serverSocket2.recv(1024))
    print(response)
    if (response.ack_or_nak == 1) and (response.checksum == True):
        idx += 1

