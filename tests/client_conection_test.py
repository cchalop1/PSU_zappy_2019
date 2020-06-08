import socket

HOST = '127.0.0.1'
PORT = 4242

def test_client_conect():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert 1
    except Exception as e:
        assert 0
    finally:
        s.close()

def test_client_welcome():
    s = socket.socket()
    try:
        s.connect((HOST, PORT))
        assert s.recv(5000).decode() == 'WELCOME\n'
    except Exception as e:
        assert 0
    finally:
        s.close()
