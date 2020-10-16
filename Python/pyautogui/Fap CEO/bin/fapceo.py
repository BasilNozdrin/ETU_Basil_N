import pyautogui


class FapCeo:
    __girls = []
    __level_up = __sell_company = __sell_confirm = (0, 0)
    __hire_all = __cancel_sell = __close_offer = (0, 0)
    __gray = [
        (191, 191, 191),
        (199, 199, 199),
        # fullscreen
        (102, 107, 125),
        (197, 197, 197),
        (188, 188, 188),
        (189, 189, 189),
    ]
    __green_and_violet = [
        # green
        (38, 184, 57),
        (40, 190, 59),
        (41, 197, 61),
        # fullscreen green
        (36, 188, 55),
        (37, 196, 57),
        # violet
        (172, 5, 193),
        (175, 5, 197),
        (182, 5, 205),
        # fullscreen violet
        (173, 0, 196),
        (180, 0, 204),
    ]
    __sell_colors = [
        (46, 44, 44),
        (15, 182, 255),
        (23, 148, 227),
        # fullscreen
        (13, 178, 255),
        (15, 173, 251),
        (126, 128, 146),
    ]

    def __init__(self, mode=''):
        """
        :param mode:
            use 'fullscreen' or 'fs' for fullscreen mode
            anything else is windowed mode
        """
        if mode in ['fullscreen', 'fs']:
            self.__girls = [
                (395, 386), (644, 241),
                (607, 500), (835, 365), (1071, 224),
                (803, 620), (1039, 485), (1272, 342),
                (1007, 738), (1231, 598), (1487, 463),
            ]
            self.__level_up = (1695, 988)
            self.__sell_company = (763, 0)
            self.__sell_confirm = (1036, 940)
            self.__hire_all = (1479, 87)
            self.__event_chest = (1647, 743)
            self.__close_offer = (1400, 148)
        else:
            self.__girls = [
                (572, 380), (744, 287),
                (715, 464), (866, 371), (1021, 275),
                (850, 544), (1005, 449), (1163, 359),
                (982, 627), (1137, 525), (1304, 431),
            ]
            self.__level_up = (1442, 783)
            self.__sell_company = (956, 127)
            self.__sell_confirm = (1017, 756)
            self.__hire_all = (1298, 185)
            self.__event_chest = (1413, 620)

        pyautogui.mouseInfo()
        pyautogui.sleep(2)

    def action_click_girl(self, n):
        x, y = self.__girls[n % 11]
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=10, interval=0.07, button='left')

    def action_level_up(self, levels=20):
        x, y = self.__level_up
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=levels, interval=0.1, button='left')

    def action_sell_company(self):
        x, y = self.__sell_company
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=1, button='left')
        x, y = self.__sell_confirm
        if pyautogui.onScreen(x, y):
            cur = pyautogui.pixel(x, y)
            pyautogui.click(x, y, clicks=1, interval=3, button='left')
            # print('sell', cur, end='\t')
            if cur not in self.__sell_colors:
                # print('selling...')
                self.action_hire()
            # else:
                # print('not ready to sell')

    def action_hire(self):
        x, y = self.__hire_all
        self.action_click_girl(0)
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=2, button='left')
        self.action_click_girl(0)

    def action_event(self):
        x, y = self.__event_chest
        self.action_click_girl(0)
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=10, interval=0.1, button='left')
        pyautogui.sleep(2)
        self.action_click_girl(0)

    def state(self):
        """
        :return:
        0 for non-game color
        1 for gray
        2 for green or violet
        """
        x, y = self.__level_up
        cur = pyautogui.pixel(x, y)
        # print('state', cur, end='\t')
        if cur in self.__gray:
            # print('gray')
            return 1
        if cur in self.__green_and_violet:
            # print('green or violet')
            return 2
        # print('bad color')
        return 0

    def looped_level_up(self, number_of_passes=1):
        for i in range(11*number_of_passes):
            self.action_click_girl(i % 11)
            if self.state() == 0:
                self.action_click_girl(i % 11)
                if self.state() == 0:
                    # print('looped_level_up stopped: wrong color')
                    return
            pyautogui.sleep(2)
            self.action_click_girl(i % 11)
            while self.state() == 2:
                self.action_level_up()

    def close_offer(self):
        x, y = self.__close_offer
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=1, button='left')


def loop(game, number_of_passes=2, sell=True, event=False):
    while game.state():
        if event:
            game.action_event()
        if sell:
            game.action_sell_company()
        game.looped_level_up(number_of_passes=number_of_passes)
        # if not game.state():
        #     game.close_offer()
    print('Process terminated')
