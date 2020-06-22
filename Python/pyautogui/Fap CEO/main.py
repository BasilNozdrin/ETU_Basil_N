from bin import fapceo as fc
from bin import fapceo_stock_market as stock


def main():
    print('Choose action:\n'
          '  -loop\n'
          '  -board room\n',
          end='')
    if input() == 'loop':
        print('Enter number of passes,'
              'sell end event options:',
              end='')
        game = fc.FapCeo()
        number_of_passes, sell, event = list(map(int, input().split()))
        fc.loop(game, number_of_passes=number_of_passes, sell=sell, event=event)
    else:
        print('Enter your board initial state:\n',
              end='')
        news, employees, bank = list(map(int, input().split()))
        stock.gen(news, employees, bank)


if __name__ == '__main__':
    main()
