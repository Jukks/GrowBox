import serial
"""
ser = serial.Serial("/dev/ttyACM0")
ser.baudrate = 9600
#ser.open()


ser.write(b"readmoisture")
readline = ser.readline()

asd = readline.decode("utf-8")
asd = asd.strip("\n")
print(asd)
"""
# ARDUINO DEVICE IN /DEV
serialDevice = "/dev/ttyACM0"

def main():
    ser = serial.Serial(serialDevice)
    ser.baudrate = 9600
    while True:
        command = input()
        if command != "lightsOn" and command != "lightsOff":
            continue
        elif command == "lightsOn":
            ser.write(bytes(command, "UTF-8"))
            confirm = ser.readline().decode("UTF-8")
            print(confirm)
        elif command == "lightsOff":
            ser.write(bytes(command, "UTF-8"))
            confirm = ser.readline().decode("UTF-8")
            print(confirm)

main()


