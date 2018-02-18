# Reads data from Arduino and saves to file
import serial
import pyrebase

config = {
  "apiKey": "AIzaSyDrr76124iABn9Ukw0NgmXFfdnnW_92thg",
  "authDomain": "threedscanner.firebaseapp.com",
  "databaseURL": "https://threedscanner.firebaseio.com",
  "storageBucket": "threedscanner.appspot.com",
}
firebase = pyrebase.initialize_app(config)

db = firebase.database()

ser = serial.Serial("COM3", 9600)
data = []


flag = True
while (flag):
    distance = ser.readline().decode().strip('\r\n')

    if ("End" in distance):
        flag = False

    data.append(distance.split(','))
data.pop(0)
data = data[:-1]

print("Finished")
ser.close()

db.child('users').push(data)

