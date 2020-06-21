from client.ai import ai
from client.ai_actions import act_dur

class Inosuke_ai(ai):
    def __init__(self):
        ai.__init__(self)
        pass

    def __del__(self):
        pass

    def select_action(self):
        self.walk()
        self.Take("food")
        self.Eject()