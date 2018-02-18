# Reads data from Arduino and saves to file

import serial
ser = serial.Serial("COM3", 9600)
data = []

with open("data.txt", "w") as f:
    flag = True
    while (flag):
        distance = ser.readline().decode().strip('\r\n')
        print(distance)
        if ("End" in distance):
            print("im exiting")
            flag = False

        data.append(distance.split(','))
    data.pop(0)
    data = data[:-1]
    print(data)
    f.write(data)
    f.flush()

print("Finished")
ser.close()
