
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

class ai_actions:
    def __init__(self):
        pass

    #move up one tile
    def Forward(self):
        print("Forward")

    #turn 90o right
    def Right(self):
        print("Right")

    #turn 90o left
    def Left(self):
        print("Left")

    #look around
    def Look(self):
        print("Look")

    #inventory
    def Inventory(self):
        print("Inventory")

    #number of team unused slots
    def Connect_nbr(self):
        print("Connect_nbr")

    #fork a player
    def Fork(self):
        print("Fork")

    #eject players from this tile
    def Eject(self):
        print("Eject")

    #take object
    def Take(self, obj):
        print("Look", obj)

    #set object down
    def Set(self, obj):
        print("Set", obj)

    #broadcast text
    def Broadcast(self, text):
        print("Broadcast", text)

    #start incantation
    def Incantation(self):
        print("Incantation")