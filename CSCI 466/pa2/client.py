# First just get two sockets to send/receive objects, 
# then get message segmenting working, 
# then sequence numbers, then acks, etc.
import socket
import sys
import random
import time
import pickle

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


port = int(sys.argv[1])
size = int(sys.argv[2])
corrupt_prob = float(sys.argv[3])

host = socket.gethostname()

input_message = input("Enter a message to translate to pirate:")
# input_message = "That boy is my friend."
segmented_message = [input_message[i:i+size] for i in range(0, len(input_message), size)]
print(segmented_message) #TEST

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect( (host, port) )

# While loop for sending segmented user input,
# and receiving ACKs from server
idx = 0
while idx < len(segmented_message):
    pac = Packet(idx+1, checksum_bool(corrupt_prob), 2, len(segmented_message[idx]), segmented_message[idx])
    # print(pac)
    clientSocket.send(pickle.dumps(pac))
    time.sleep(1)
    response = pickle.loads(clientSocket.recv(1024))
    print(response)
    if (response.ack_or_nak == 1) and (response.checksum == True):
        idx += 1

# While loop for receiving segmented pirate message,
# and sending ACKs back
pirate_packets = []


clientSocket.close()


host = socket.gethostname()

clientSocket2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket2.bind( (host, port) )

print("Ready for connection on port", port)
clientSocket2.listen(1)

conn2, addr2 = clientSocket2.accept()


done = False
while not done:
    pac = pickle.loads(conn2.recv(1024))
    print(pac)
    if pac.checksum == True:            # if received packet valid
        if (len(pirate_packets) > 0) and (pirate_packets[-1].seq == pac.seq):     # checks if previous packet matches current one (retransmission)
            pass
        else:
            pirate_packets.append(pac)     # replace with new packet if true
        if pac.message.endswith(".") or pac.message.endswith("?") or pac.message.endswith("!"):
            reply = Packet(0, True, 1, 0, "")   # create ACK response
            conn2.send(pickle.dumps(reply))
            done = True
        else:
            checksum = checksum_bool(corrupt_prob)
            reply = Packet(0, checksum, 1, 0, "")   # create ACK response
            conn2.send(pickle.dumps(reply))
    elif pac.checksum == False:         # if recieved packet is invalid
        reply = Packet(0, True, 0, 0, "")       #create NAK response
        conn2.send(pickle.dumps(reply))

full_string = ""
for pack in pirate_packets:
    full_string += pack.message

print(full_string)


