import subprocess 
import vlc
import playsound
import time
import socket

LOCAL_UDP_IP = "192.168.1.2"
SHARED_UDP_PORT = 5005
PAUSE = False

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # Internet  # UDP
sock.bind((LOCAL_UDP_IP, SHARED_UDP_PORT))

# subprocess works 
# subprocess.call(["afplay", "NCT.mp3"])

p = vlc.MediaPlayer("/Users/CynthiaVu1/Desktop/NCT.mp3")
p.play()
while True:
    data, addr = sock.recvfrom(2048)  # buffer size is 1024 byte
    if (ord(data) == 10):
        if (PAUSE): # currently paused
            p.play()
            PAUSE = True
        else: 
            p.pause()
            PAUSE = False
    print("received message:", data)

    # pass
# playsound works 
# playsound.playsound("/Users/CynthiaVu1/Desktop/NCT.mp3", True)