print("python is pythoning")
import pip._vendor.requests as requests 
r = requests.get("http://v2.jokeapi.dev/joke/any")

print(r.status_code)
#print(r.headers)
#print(r.context)
print(r.text)

#r = requests.get("http://gaia.cs.umass.edu/wireshark-labs")