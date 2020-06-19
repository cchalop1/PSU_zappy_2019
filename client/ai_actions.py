from ai_stats import ai_stats
from Client import Client

act_dur = {
    "Forward" : 7,
    "Right" : 7,
    "Left" : 7,
    "Look" : 7,
    "Inventory" : 1,
    "Broadcast" : 7,
    "Connect_nbr" : 0,
    "Fork" : 42,
    "Eject" : 7,
    "Take" : 7,
    "Set" : 7,
    "Incantation" : 300
}

recipe = [ {},
    { "linemate" : 1, "deraumere" : 0, "sibur" : 0, "mendiane" : 0, "phiras" : 0, "thystame" : 0 },
    { "linemate" : 1, "deraumere" : 1, "sibur" : 1, "mendiane" : 0, "phiras" : 0, "thystame" : 0 },
    { "linemate" : 2, "deraumere" : 0, "sibur" : 1, "mendiane" : 0, "phiras" : 2, "thystame" : 0 },
    { "linemate" : 1, "deraumere" : 1, "sibur" : 2, "mendiane" : 0, "phiras" : 1, "thystame" : 0 },
    { "linemate" : 1, "deraumere" : 2, "sibur" : 1, "mendiane" : 3, "phiras" : 0, "thystame" : 0 },
    { "linemate" : 1, "deraumere" : 2, "sibur" : 3, "mendiane" : 0, "phiras" : 1, "thystame" : 0 },
    { "linemate" : 2, "deraumere" : 2, "sibur" : 2, "mendiane" : 2, "phiras" : 2, "thystame" : 1 }]

stones = ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]

class ai_actions(ai_stats, Client):
    def __init__(self):
        Client.__init__(self)
        ai_stats.__init__(self)
        pass

    #move up one tile
    def Forward(self):
        self.time_unit -= act_dur["Forward"]
        self.sock.send(("Forward\n").encode())
        print("Forward")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #turn 90o right
    def Right(self):
        self.time_unit -= act_dur["Right"]
        self.sock.send(("Right\n").encode())
        print("Right")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #turn 90o left
    def Left(self):
        self.time_unit -= act_dur["Left"]
        self.sock.send(("Left\n").encode())
        print("Left")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #look around
    def Look(self):
        self.time_unit -= act_dur["Look"]
        self.sock.send(("Look\n").encode())
        print("Look")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #inventory
    def Inventory(self):
        self.time_unit -= act_dur["Inventory"]
        self.sock.send(("Inventory\n").encode())
        print("Inventory")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #number of team unused slots
    def Connect_nbr(self):
        self.time_unit -= act_dur["Connect_nbr"]
        self.sock.send(("Connect_nbr\n").encode())
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #fork a player
    def Fork(self):
        self.time_unit -= act_dur["Fork"]
        self.sock.send(("Fork\n").encode())
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #eject players from this tile
    def Eject(self):
        self.time_unit -= act_dur["Eject"]
        self.sock.send(("Eject\n").encode())
        print("Eject")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #take object
    def Take(self, obj):
        self.time_unit -= act_dur["Look"]
        self.sock.send(("Look " + obj +"\n").encode())
        print("Take")
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #set object down
    def Set(self, obj):
        self.time_unit -= act_dur["Set"]
        self.sock.send(("Set " + obj + "\n").encode())
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #broadcast text
    def Broadcast(self, text):
        self.time_unit -= act_dur["Broadcast"]
        self.sock.send(("Broadcast " + text + "\n").encode())
        self.reply = self.sock.recv(5000).decode()
        print(self.reply)

    #start incantation
    def Incantation(self):
        self.time_unit -= act_dur["Incantation"]
        self.sock.send(("Incantation\n").encode())
        self.reply = self.sock.recv(5000).decode()