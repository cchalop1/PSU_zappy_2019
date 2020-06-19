import sys
import getopt
import socket

EXIT_SUCCESS = 0
EXIT_ERROR = 84

def print_help():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("      port        is the port number")
    print("      name       is the name of the team")
    print("      machine    is the name of the machine; localhost by default")


class Client:
    def __init__(self):
        self.host = None
        self.port = None
        self.team_name = None
        self.sock = socket.socket()
        self.parse_argument()
        self.conect_to_server()

    def parse_argument(self):
        if len(sys.argv) == 2 and sys.argv[1] == "-help":
            print_help()
            exit(0)
        optlist, _ = getopt.getopt(sys.argv[1:], 'n:h:p:')
        for name, value in optlist:
            if name == "-h":
                self.host = str(value)
            elif name == "-n":
                self.team_name = str(value)
            elif name == "-p":
                self.port = int(value)

    def conect_to_server(self):
        if self.port != None and self.host != None and self.team_name != None:
            try:
                self.sock.connect((self.host, self.port))
                self.sock.send((self.team_name + "\n").encode())
            except Exception as e:
                print("ERROR: conect to server")
                exit(EXIT_ERROR)
