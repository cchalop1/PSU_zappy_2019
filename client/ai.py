from ai_actions import ai_actions, act_dur, recipe
from ai_stats import ai_stats
from path import path

class ai(ai_actions, ai_stats):
    def __init__(self):
        super().__init__(self)
        pass

    def __del__(self):
        pass

    def loop(self):
        while 1:
            aswer = self.get_return()
            self.select_action()

    def select_action(self):
        pass

    def have_time(self, func):
        if self.time_unit >= act_dur[func]:
            return True
        return False

    def get_return(self):
        ret = ""
        return ret

    def is_dead(self):
        print("I'm starving ...")
        self.__del__()

    def get_connect_nbr(self):
        self.Connect_nbr()
        return self.get_return()

    def get_inventory(self):
        self.Inventory()
        ret = self.get_return()
        ret.replace(']', '')
        ret.replace(',', '')
        ret.split(' ')

        self.inventory["linemate"] = int(ret[1])
        self.inventory["deraumere"] = int(ret[3])
        self.inventory["sibur"] = int(ret[5])
        self.inventory["mendiane"] = int(ret[7])
        self.inventory["phiras"] = int(ret[9])
        self.inventory["thystame"] = int(ret[11])

    def get_look(self):
        self.vision.clear()
        self.Look()
        ret = self.get_return()
        ret.replace(']', '')
        ret.replace('[', '')
        ret.split(', ')
        for i in ret:
            a = i.split(' ')
            self.vision.append(a)

    def can_lvl_up(self):
        if (self.inventory["linemate"] < recipe[self.level]["linemate"] or
        self.inventory["deraumere"] < recipe[self.level]["deraumere"] or
        self.inventory["sibur"] < recipe[self.level]["sibur"] or
        self.inventory["mendiane"] < recipe[self.level]["mendiane"] or
        self.inventory["phiras"] < recipe[self.level]["phiras"] or
        self.inventory["thystame"] < recipe[self.level]["thystame"]):
            return False
        return True

    def needed(self):
        if self.inventory["thystame"] < recipe[self.level]["thystame"]:
            return "thystame"
        elif self.inventory["phiras"] < recipe[self.level]["phiras"]:
            return "phiras"
        elif self.inventory["mendiane"] < recipe[self.level]["mendiane"]:
            return "mendiane"
        elif self.inventory["sibur"] < recipe[self.level]["sibur"]:
            return "sibur"
        elif self.inventory["deraumere"] < recipe[self.level]["deraumere"]:
            return "deraumere"
        elif self.inventory["linemate"] < recipe[self.level]["linemate"]:
            return "linemate"
        else:
            return ""

    def go_to(self, path):
        for i in range(0, path.forward):
            self.Forward()
        if path.left > 0:
            self.Left()
            for i in range(0, path.left):
                self.Forward()
        elif path.right() > 0:
            self.Right()
            for i in range(0, path.left):
                self.Forward()

    def go_to_n(self, n):
        p = path(0,0,0)
        return p

    def _find_that(self, obj):
        i = 0
        while (i < len(self.vision)):
            if obj in self.vision[i]:
                pass ####
            i += 1
        return 0 ###

    def find_that(self, obj):
        p = path(0,0,0)
        self.get_look()
        n = self._find_that(obj)
        return p

    def get_object(self, obj):
        p = self.find_that(obj)
        self.go_to(p)
        self.Take(obj)
        pass
