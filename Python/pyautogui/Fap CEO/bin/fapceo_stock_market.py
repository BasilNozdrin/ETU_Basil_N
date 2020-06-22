

class BoardRoom:
    __actions = [
        [3, 0, -1],
        [-3, -2, 3],
        [2, 0, -2],
        [-2, 2, 0],
        [0, -3, 2],
        [0, 3, -2],
    ]
    __state = [0, 0, 0]

    def __init__(self, state=(8, 8, 8)):
        (news, employees, bank) = state
        self.__state = [news, employees, bank]

    def act(self, n):
        self.__state = list(
            map(
                lambda x, y: x + y,
                self.__state,
                self.__actions[n % 6])
        )

    def quality(self):
        _quality = 0
        for x in self.__state:
            _quality += abs(8-x)
        return _quality

    def get_state(self):
        return self.__state


def gen(news, employees, bank):
    # res = set()
    best_sequence = "No result"
    best_quality = 10
    for i in range(6**5):
        br = BoardRoom((news, employees, bank))
        n = i
        s = ""
        for j in range(5):
            br.act(n)
            s += str(n % 6 + 1)
            n //= 6
        s += "-> "
        if sum(map(lambda x: 1 if x < 0 else 0, br.get_state())) or br.quality() > 5:
            continue
        if br.quality() < best_quality:
            best_quality = br.quality()
            best_sequence = s + "|".join(map(str, br.get_state())) + " Q = " + str(br.quality())
        # res.add(s + "|".join(map(str, br.get_state())) + "\tQ =" + str(br.quality()))
    # print("\n".join(res))
    print(best_sequence)


if __name__ == "__main__":
    gen(6, 11, 9)
