from ai_actions import ai_actions, act_dur, recipe, stones
from ai_stats import ai_stats
from path import path
from math import sqrt
import random as rd
import time


class Tile:
    def __init__(self):
        self.x = None
        self.y = None
        self.inventory = {
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0
        }
        self.fruit = 0
        self.contain_player = None

def toto(s):
    return s.strip()


class ai(ai_actions):
    def __init__(self):
        ai_actions.__init__(self)
        time.sleep(0.1)
        self.get_return()
        self.get_look()
        # self.loop()

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



    def parse_look_response(self, str):
        data = []
        print(str)
        str = str.replace(",", "")
        str = str.split('[')[1]
        str = str.split(']')[0]
        str = str.split('\n')
        str = list(map(toto, str))
        for i in range(0, len(str) - 1):
            line = str[i].split(' ')
            tile = Tile()
            tile.x = int(line[2])
            tile.y = int(line[3])
            tile.inventory["linemate"] = int(line[5])
            tile.inventory["deraumere"] = int(line[6])
            tile.inventory["sibur"] = int(line[7])
            tile.inventory["mendiane"] = int(line[8])
            tile.inventory["phiras"] = int(line[9])
            tile.inventory["thystame"] = int(line[10])
            tile.fruit += int(line[4])
            tile.contain_player = True if int(line[0]) == 1 else False
            data.append(tile)
        for elem in range(0, len(data)):
            print(data[elem].x)
            print(data[elem].y)
            print(data[elem].inventory)
            print(data[elem].contain_player)
        return data;

    def get_look(self):
        self.vision = ""
        self.Look()
        ret = self.get_return()
        self.parse_look_response(ret)

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

    # can do better ?
    def _find_that(self, obj):
        self.vision.split(',')
        print(self.vision.__class__)
        print("seach path to :", obj)
        print("visio = ", self.vision)
        print("visio = ", self.vision[0], "\n\n")
        print(self.vision)
        if obj in self.vision:
            print("path find")
            return self.get_path(1)
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
