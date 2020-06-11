from ai_stats import ai_stats

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

class ai_actions(ai_stats):
    def __init__(self):
        pass

    #move up one tile
    def Forward(self):
        self.time_unit -= act_dur["Forward"]
        print("Forward")

    #turn 90o right
    def Right(self):
        self.time_unit -= act_dur["Right"]
        print("Right")

    #turn 90o left
    def Left(self):
        self.time_unit -= act_dur["Left"]
        print("Left")

    #look around
    def Look(self):
        self.time_unit -= act_dur["Look"]
        print("Look")

    #inventory
    def Inventory(self):
        self.time_unit -= act_dur["Inventory"]
        print("Inventory")

    #number of team unused slots
    def Connect_nbr(self):
        self.time_unit -= act_dur["Connect_nbr"]
        print("Connect_nbr")

    #fork a player
    def Fork(self):
        self.time_unit -= act_dur["Fork"]
        print("Fork")

    #eject players from this tile
    def Eject(self):
        self.time_unit -= act_dur["Eject"]
        print("Eject")

    #take object
    def Take(self, obj):
        self.time_unit -= act_dur["Look"]
        print("Look", obj)

    #set object down
    def Set(self, obj):
        self.time_unit -= act_dur["Set"]
        print("Set", obj)

    #broadcast text
    def Broadcast(self, text):
        self.time_unit -= act_dur["Broadcast"]
        print("Broadcast", text)

    #start incantation
    def Incantation(self):
        self.time_unit -= act_dur["Incantation"]
        print("Incantation")