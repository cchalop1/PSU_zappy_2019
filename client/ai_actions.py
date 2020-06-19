from ai_stats import ai_stats
from Client import Client
import socket
import select

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

    def is_dead(self):
        print("I'm starving ...")
        self.__del__()
        exit(0)

    def get_return(self):
        arg = [self.sock]
        clients_a_lire = []
        ret = self.reply
        try:
            clients_a_lire, wlist, xlist = select.select(arg, [], [], 0.05)
        except select.error:
            pass
        for i in clients_a_lire:
            ret = i.recv(1024).decode()
            if ret == "dead\n":
                self.is_dead()
        print(ret)
        return ret

    def do_action(self, action):
        self.time_unit -= act_dur[action]
        self.sock.send((action + "\n").encode())
        print(action)
        self.reply = self.get_return()

    #move up one tile
    def Forward(self):
        self.do_action("Forward")

    #turn 90o right
    def Right(self):
        self.do_action("Right")

    #turn 90o left
    def Left(self):
        self.do_action("Left")

    #look around
    def Look(self):
        self.do_action("Look")

    #inventory
    def Inventory(self):
        self.do_action("Inventory")

    #number of team unused slots
    def Connect_nbr(self):
        self.do_action("Connect_nbr")

    #fork a player
    def Fork(self):
        self.do_action("Fork")

    #eject players from this tile
    def Eject(self):
        self.do_action("Eject")

    #take object
    def Take(self, obj):
        self.time_unit -= act_dur["Take"]
        self.sock.send(("Take " + obj +"\n").encode())
        print("Take")
        self.reply = self.get_return()
        print(self.reply)

    #set object down
    def Set(self, obj):
        self.time_unit -= act_dur["Set"]
        self.sock.send(("Set " + obj + "\n").encode())
        self.reply = self.get_return()
        print(self.reply)

    #broadcast text
    def Broadcast(self, text):
        self.time_unit -= act_dur["Broadcast"]
        self.sock.send(("Broadcast " + text + "\n").encode())
        self.reply = self.get_return()
        print(self.reply)

    #start incantation
    def Incantation(self):
        self.do_action("Incantation")