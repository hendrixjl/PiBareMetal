#!/usr/bin/python3
import serial
import sys


#def boot_target( serialPort ):
#    boot = "@\n".encode('ascii')
#    serialPort.write(boot)
    

def main(port, upload_file):
    try:
        serialPort = serial.Serial(port, 115200)
        serialPort.close()
        serialPort.open()
        keep_waiting = True
        print("Press the reset button on the Raspberry PI")
        while keep_waiting:
            data = serialPort.readline().decode('ascii').strip().rstrip()
            #print(data)
            if 'IHEX' in data:
                keep_waiting = False
        print("Heard from board")

        with open(upload_file, 'r') as infile:
            for line in infile:
                serialPort.write(line.encode('ascii'))
        print("Uploaded program")
        serialPort.write('g'.encode('ascii'))
        serialPort.flush()
        while True:
            data = serialPort.readline().decode('ascii').strip().rstrip()
            print(data)
            if '--' in data:
                break
        
    except serial.SerialException as e:
        fh.write("I/O error({0}): {1}\n".format(e.errno, e.strerror))
        fh.write("Is someone else on the com1 port?\n")
        fh.flush()
        exit(1)

    
if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
    exit(0)

