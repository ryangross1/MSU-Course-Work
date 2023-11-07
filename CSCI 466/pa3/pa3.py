import sys
import pip._vendor.requests as requests

#get interface table
interfaces_r = requests.get("https://www.cs.montana.edu/pearsall/classes/fall2023/466/programs/prefix_matching.csv")
# print(interfaces_r.text)

#create and fill interface dictionary, key: interface, value: rule
interface_input_string = interfaces_r.text
interfaces_lines = interface_input_string.strip().split("\n")[1:]
interface_dict = {}
for l in interfaces_lines:
    split = l.split(",")
    interface_dict[split[1]] = split[0].strip("\n")

# print(interface_dict)

ips = requests.get("https://www.cs.montana.edu/pearsall/classes/fall2023/466/programs/packets.csv").text.strip().split("\n")[1:]

#creaate and fill packets dictionary, key: IPv4, value: binary
packets_dict = {}
#ipv4_addresses = list of addresses from packets.csv in dotted decimal IPv4 notation
for each in ips:
    binary = (''.join([bin(int(x)+256)[3:] for x in each.split('.')]))
    # print(each)
    packets_dict[each] = binary

br = "------------------------------------------------------"
print("\t\t   Forwarding Table")
print(br)
print("\tPrefix\t\t\t\tInterface")
print(br)
for i in interface_dict.items():
    print(i[1], "\t", i[0])
print(br)

for dec_ip in packets_dict.keys(): #compare interface_dict value (rule) to packets_dict value (binary)
    bin_ip = packets_dict[dec_ip]
    matched = 0
    best = ''
    wilds = 0
    for rule in interface_dict.keys():
        count = 0
        idx = 0
        while(bin_ip[idx] == interface_dict[rule][idx]):
            count += 1
            idx += 1

        if (count > matched and interface_dict[rule][idx] == '*'):
            matched = count
            best = rule
            wilds = len(interface_dict[rule]) - matched
    print("Packet:", dec_ip, "\tis forwarded to interface", best)




