from ai_actions import ai_actions, act_dur
from ai_stats import ai_stats

class ai(ai_actions, ai_stats):
    def __init__(self):
        super().__init__(self)
        pass

    def __del__(self):
        print("I'm starving ...")

    def __call__(self):
        pass

    def TryAction(self, func):
        if self.food * 126 >= act_dur[func]:
            return True
        return False

    def GetReturn(self):
        ret = ""
        return ret

    def GetInventory(self):
        self.Inventory()
        ret = self.GetReturn()
        ret.replace(']', '')
        ret.replace(',', '')
        ret.split(' ')

        self.food = int(ret[1])
        self.linemate = int(ret[3])
        self.deraumere = int(ret[5])
        self.sibur = int(ret[7])
        self.mendiane = int(ret[9])
        self.phiras = int(ret[11])
        self.thystame = int(ret[13])

    def GetLook(self):
        self.vision.clear()
        self.Look()
        ret = self.GetReturn()
        ret.replace(']', '')
        ret.replace('[', '')
        ret.split(', ')
        for i in ret:
            a = i.split(' ')
            self.vision.append(a)

