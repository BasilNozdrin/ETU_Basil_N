import fapceo as fc


def main():
    game = fc.FapCeo()
    while game.state():
        game.action_sell_company()
        game.action_hire_all()
        game.looped_level_up(number_of_passes=2)
    print('Process terminated')


if __name__ == '__main__':
    main()
