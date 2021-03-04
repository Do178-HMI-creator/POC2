# Python 3.8
import socket
from time import sleep
import math
UDP_IP = "127.0.0.1"
UDP_PORT = 7777
sock = socket.socket


def connect():
    global sock
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def send(MESSAGE):
    global sock
    sock.sendto(bytes(MESSAGE, "utf-8"), (UDP_IP, UDP_PORT))


if __name__ == '__main__':
    connect()
    x=0.0
    y=0.0
    degree=0
    r=0.01
    r3 = 0.03
    r2 = 0.5

    x1 = -0.4
    y1 = -0.3
    x2 = 0.4
    y2 = -0.3
    x3 = 0.4
    y3 = 0.3
    x4 = -0.4
    y4 = 0.3


    while True:
        send("my_agtGpLine.point.x="+str(x+r2*math.sin(degree)))
        send("my_agtGpLine.point.y="+str(y+r2*math.cos(degree)))

        send("my_agtGpDot6.point.xc="+str(x+r2*math.sin(degree)))
        send("my_agtGpDot6.point.yc="+str(y+r2*math.cos(degree)))

        send("my_agtGpDot1.point.x="+str(r*math.cos(degree)))
        send("my_agtGpDot1.point.y="+str(r*math.sin(degree)))
        send("my_agtGpDot2.point.x="+str(r*math.cos(degree)))
        send("my_agtGpDot2.point.y="+str(r*math.sin(degree)))
        send("my_agtGpDot3.point.x="+str(r*math.cos(degree)))
        send("my_agtGpDot3.point.y="+str(r*math.sin(degree)))
        send("my_agtGpDot4.point.x="+str(r*math.cos(degree)))
        send("my_agtGpDot4.point.y="+str(r*math.sin(degree)))

        send("my_agtGpRectangle.point.x1="+str(r*math.cos(degree)))
        send("my_agtGpRectangle.point.y1="+str(r*math.sin(degree)))
        send("my_agtGpRectangle.point.x2="+str(r*math.cos(degree)))
        send("my_agtGpRectangle.point.y2="+str(r*math.sin(degree)))
        send("my_agtGpRectangle.point.x3="+str(r*math.cos(degree)))
        send("my_agtGpRectangle.point.y3="+str(r*math.sin(degree)))
        send("my_agtGpRectangle.point.x4="+str(r*math.cos(degree)))
        send("my_agtGpRectangle.point.y4="+str(r*math.sin(degree)))



        degree=degree+2*math.pi/24
        sleep(0.2)
