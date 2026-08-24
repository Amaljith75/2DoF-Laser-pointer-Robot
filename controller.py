import pygame
import serial
import time

# CHANGE THIS TO YOUR ESP32 COM PORT
ser = serial.Serial("COM3", 115200)
time.sleep(2)

pygame.init()
pygame.joystick.init()

count = pygame.joystick.get_count()
print("Controllers found:", count)

if count == 0:
    print("No controller detected!")
    quit()

joy = pygame.joystick.Joystick(0)
joy.init()

print("Connected:", joy.get_name())

while True:
    pygame.event.pump()

    lx = joy.get_axis(0)
    ly = joy.get_axis(1)

    if lx < -0.4:
        ser.write(b'L')
    elif lx > 0.4:
        ser.write(b'R')

    if ly < -0.4:
        ser.write(b'U')
    elif ly > 0.4:
        ser.write(b'D')

    time.sleep(0.01)