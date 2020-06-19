import time
import socket
import subprocess


HOST = '127.0.0.1'
PORT = 4242
BUFFER_MAX = 5000
EXIT_ERROR = 84


class MySocket:
    def __init__(self, name):
        self.name = name
        self.sock = socket.socket()

    def __del__(self):
        self.sock.close()

    def send(self, str):
        self.sock.send(str.encode())

    def read(self):
        time.sleep(.2)
        return self.sock.recv(BUFFER_MAX).decode()

    def conect(self):
        try:
            self.sock.connect((HOST, PORT))
            self.sock.send((self.name + "\n").encode())
        except Exception as e:
            print("ERROR: conect to server")
            exit(EXIT_ERROR)

def test_get_time_commande():
    subprocess.run(["ls", "-l"])

    graphic = MySocket('GRAPHIC')
    player = MySocket('toto')

    # graphic.conect()
    graphic.conect()
    assert graphic.read() == 'WELCOME\n'
    assert 1
