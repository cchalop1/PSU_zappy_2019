from ai import ai
from ai_actions import act_dur

class first_ai(ai):
    def __init__(self):
        ai.__init__(self)
        pass

    def __del__(self):
        pass

    def select_action(self):
        self.get_object("food")

        # if self.can_lvl_up() == True and self.can_lvlup == False:
        #     self.Broadcast(str("Up to", self.level + 1))
        #     self.can_lvlup = True

        # if self.time_unit < 500: #food critical
        #     self.find_that("food")
        #     print("a")
        # elif self.time_unit < 1000: #food ok , walk and take what you find
        #     print("b")
        #     self.walk()
        # #elif can_lvl_up == True and self.time_unit > act_dur["Incantation"] + 50:
        # #    lvl_up
        # elif self.get_connect_nbr() > self.max_pl - self.level and self.time_unit > act_dur["Fork"] + 50:
        #     print("c")
        #     self.Fork()
        # else:
        #     print("d")
        #     self.get_object(self.needed())
