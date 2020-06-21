#!/usr/bin/python3
from client.Inosuke import Inosuke_ai
from client.Zenitsu import Zenitsu

def main():
    ai_list = [Inosuke_ai, Zenitsu]
    ai = ai_list[1]()
