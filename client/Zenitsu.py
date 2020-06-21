from client.ai import ai
from client.ai_actions import act_dur, recipe

class Zenitsu(ai):
    def __init__(self):
        ai.__init__(self)
        pass

    def __del__(self):
        pass

    def select_action(self):
        if self.can_lvl_up() == True and self.can_lvlup == False:
            #self.Broadcast(str("Up to", self.level + 1))
            self.can_lvlup = True

        if self.time_unit < 500: #food critical
            self.get_object("food")
        #elif can_lvl_up == True and self.time_unit > act_dur["Incantation"] + 50:
        #    lvl_up
        else:
            self.get_object(self.needed())
