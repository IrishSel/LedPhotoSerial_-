// не доделали код Работает только 1) вкл 2) выкл 3) менять яркость в зависимости от освещения
import serial
import time

lengths = {'с': 3,
           'u': 0,
           'd': 0}

def get_connection(port):
    ser = serial.Serial(port, timeout = 1)
    return ser

def send (ser,message,mesg_len):
    ser.write(message)
    time.sleep(0.1)
    result = None
    if mesg_len != 0:
        data = ser.read(mesg_len)
        result = data.decode()
        result = result.strip()
        print(result)
    return result

Ther_holds = 850
if __name__ == '__main__':
    ser = get_connection("COM10")
    while True:
        inp = input("Enter command: ")
        #length = lengths.get(inp, 17)
        #send(ser, inp.encode(), length)
        cmd = 'с'
        val = send(ser, cmd.encode(), lengths[cmd])

        if val:
            val = int(val)
            print(f'Val as int {val}')
            if val < Ther_holds:
                send(ser, 'u'.encode(), 0)
            else:
                send(ser, 'd'.encode(), 0)
        time.sleep(1)
