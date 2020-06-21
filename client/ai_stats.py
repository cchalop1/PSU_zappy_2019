
class ai_stats:
    def __init__(self):
        self.level = 1
        self.max_pl = 6
        self.time_unit = 1260
        self.inventory = {
            "linemate" : 0,
            "deraumere" : 0,
            "sibur" : 0,
            "mendiane" : 0,
            "phiras" : 0,
            "thystame" : 0
        }
        self.vision = []
        self.can_lvlup = False
        self.want_lvlup = 0
        self.reply = ""