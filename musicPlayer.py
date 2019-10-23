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
volume = 50 
increaseCount = 0
decreaseCount = 0

# Initialze MediaPlayer with song on my desktop
# Replace file path to anything, as long as there is no space involve 
p = vlc.MediaPlayer("/Users/CynthiaVu1/Desktop/Vushi.mp3")
p.audio_set_volume(volume)
p.play()

# While the song plays, keep checking for UDP packets 
while True:
    data, addr = sock.recvfrom(2048)  # buffer size is 1024 byte
    print(data)
    # Deals with the pause and play functionality 
    if (ord(data[0]) == 65):
        if (PAUSE): # currently paused
            p.play()
            PAUSE = True
        else: 
            p.pause()
            PAUSE = False

    # Deals with the volume 
    if (ord(data[1]) == 67):
        increaseCount += 1

        # User moved enough to increase volume 
        if (increaseCount == 10):
            if (volume != 100): 
                volume += 10
                p.audio_set_volume(volume)
                print("increased")
            increaseCount = 0
    else:
        decreaseCount += 1
        # User hasn't moved in a while, so decrease volume
        if (decreaseCount == 20):
            if (volume != 0):
                volume -= 10
                p.audio_set_volume(volume)
                print("decreased")
            decreaseCount= 0
