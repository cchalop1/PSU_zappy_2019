import socket
import time

HOST = '127.0.0.1'
PORT = 4242


def test_bad_commande():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert s.recv(5000).decode() == 'WELCOME\n'
        s.send('tutu\n'.encode())
        assert s.recv(5000).decode() == 'ko\n'
    except Exception as e:
        assert 0
    finally:
        s.close()


def test_get_time_commande():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert s.recv(5000).decode() == 'WELCOME\n'
        s.send('GRAPHIC\n'.encode())
        time.sleep(.2)
        s.send('sgt\n'.encode())
        assert s.recv(5000).decode() == 'sgt 200\n'
    except Exception as e:
        assert 0
    finally:
        s.close()

def test_get_time_commande():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert s.recv(5000).decode() == 'WELCOME\n'
        s.send('GRAPHIC\n'.encode())
        time.sleep(.2)
        s.recv(5000).decode()
        time.sleep(.2)
        s.send('tna\n'.encode())
        assert s.recv(5000).decode() == 'tna toto\ntna tata\n'
    except Exception as e:
        assert 0
    finally:
        s.close()
