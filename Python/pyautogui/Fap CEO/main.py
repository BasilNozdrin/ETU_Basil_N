import fapceo as fc


def loop_with_sell(game, number_of_passes=3):
    while game.state():
        game.action_sell_company()
        game.action_hire_all()
        game.looped_level_up(number_of_passes=number_of_passes)
    print('Process terminated')


def loop_without_sell(game, number_of_passes=3):
    while game.state():
        game.looped_level_up(number_of_passes=number_of_passes)
    print('Process terminated')


def main():
    game = fc.FapCeo()
    options = {
        1: loop_with_sell,
        2: loop_without_sell,
    }
    options[1](game, 2)


if __name__ == '__main__':
    main()
