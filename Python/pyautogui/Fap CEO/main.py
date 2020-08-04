from bin import fapceo as fc
from bin import fapceo_stock_market as stock

# from pyautogui import mouseInfo as a


def main():
    print('Choose action:\n'
          '  -loop\n'
          '  -board room\n',
          end='')
    if input() in ['loop', 'lp', 'l']:
        print('Enter number of passes,'
              'sell, event and fullscreen options:',
              end='')
        data = list(map(int, input().split()))
        number_of_passes, sell, event = data[:3]
        if data[3]:
            game = fc.FapCeo('fullscreen')
        else:
            game = fc.FapCeo('')
        fc.loop(game, number_of_passes=number_of_passes, sell=sell, event=event)
    else:
        print('Enter your board initial state:\n',
              end='')
        try:
            data = input().split()
            news, employees, bank = list(map(int, data[:3]))
            stock.gen(news, employees, bank)
        except IndexError:
            print('Not enough arguments')
        except ValueError:
            print('Wrong data')


if __name__ == '__main__':
    main()
