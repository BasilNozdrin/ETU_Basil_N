import random


def generate(ammount, a, b):
    return [int(random.random()*1000%(b-a)+a) for _ in range(ammount)]


def main():
    print(" ".join(map(str, generate(25, 100, 1000))))

main()
