import socket
import time

HOST = '127.0.0.1'
PORT = 4242


def test_map_size():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert s.recv(5000).decode() == 'WELCOME\n'
        time.sleep(.2)
        s.send('msz\n'.encode())
        assert s.recv(5000).decode() == 'msz 10 10\n'
    except Exception as e:
        assert 0
    finally:
        s.close()
