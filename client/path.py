
class path():
    def __init__(self, forward, left, right):
        self.forward = forward
        self.left = left
        self.right = right

    def time(self):
        return self.forward * 7 + (0 if self.left == 0 else self.left + 1) * 7 + (0 if self.right == 0 else self.right + 1) * 7