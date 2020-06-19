from ai_actions import ai_actions, act_dur, recipe, stones
from ai_stats import ai_stats
from path import path
from math import sqrt
import random as rd

class ai(ai_actions):
    def __init__(self):
        ai_actions.__init__(self)
        self.get_return()
        self.loop()

    def __del__(self):
        pass

    def loop(self):
        while 1:
            self.select_action()

    def select_action(self):
        pass

    def walk(self):
        i = rd.randrange(8)
        if i == 0:
            self.Left()
        elif i == 1:
            self.Right()
        else:
            self.Forward()

    def have_time(self, func):
        if self.time_unit >= act_dur[func]:
            return True
        return False

    def get_connect_nbr(self):
        self.Connect_nbr()
        return int(self.get_return())

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
        ret.split(' ')
        print("ret =", ret)
        for i in ret:
            a = i.split(' ')
            self.vision.append(a)

    def can_lvl_up(self):
        for i in stones:
            if self.inventory[i] < recipe[self.level][i]:
                return False
        return True

    def needed(self):
        for i in stones:
            if self.inventory[i] < recipe[self.level][i]:
                return i
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

    def get_path(self, n):
        f = round(sqrt(n))
        dir = n  - (f**2 + f)
        l = 0 if dir >= 0 else dir * -1
        r = 0 if dir <= 0 else dir
        p = path(f,l,r)
        return p

    ### can do better ?
    def _find_that(self, obj):
        i = 0
        print("seach path to :", obj)
        while (i < len(self.vision)):
            print("vision = ",self.vision[i])
            if obj in self.vision[i]:
                print("path find")
                return self.get_path(i)
            i += 1
        print("no path find")
        return path(-1,-1,-1)

    def find_that(self, obj):
        p = path(0,0,0)
        self.get_look()
        p = self._find_that(obj)
        print("p =", p)
        return p

    def get_object(self, obj):
        print("obj =", obj)
        p = self.find_that(obj)
        if p.forward == -1:
            self.walk()
        else:
            self.go_to(p)
            self.Take(obj)
