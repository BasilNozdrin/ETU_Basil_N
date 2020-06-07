import pyautogui


class FapCeo:
    __girls = []
    __level_up = __sell_company = __sell_confirm = __hire_all = (0, 0)

    __gray = [
        (191, 191, 191),
        (199, 199, 199),
    ]
    __green_and_violet = [
        (38, 184, 57),
        (40, 190, 59),
        (41, 197, 61),

        (172, 5, 193),
        (175, 5, 197),
        (182, 5, 205),
    ]

    def __init__(self, mode=''):
        """
        :param mode:
            use 'fullscreen' or 'fs' for fullscreen mode
            anything else is windowed mode
        """
        if mode == 'fullscreen' or mode == 'fs':
            self.__girls = [
                (395, 386), (644, 241),
                (607, 500), (835, 365), (1071, 224),
                (803, 620), (1039, 485), (1272, 342),
                (1007, 738), (1231, 598), (1487, 463),
            ]
            self.__level_up = (1695, 988)
            self.__sell_company = (974, 30)
            self.__sell_confirm = (1181, 885)
            self.__hire_all = (1479, 87)
        else:
            self.__girls = [
                (572, 380), (744, 287),
                (715, 464), (866, 371), (1021, 275),
                (850, 544), (1005, 449), (1163, 359),
                (982, 627), (1137, 525), (1304, 431),
            ]
            self.__level_up = (1442, 783)
            self.__sell_company = (951, 157)
            self.__sell_confirm = (1085, 707)
            self.__hire_all = (1298, 185)

        pyautogui.mouseInfo()
        pyautogui.sleep(2)

    def action_click_girl(self, n):
        x, y = self.__girls[n % 11]
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=10, interval=0.01, button='left')

    def action_level_up(self, levels=20):
        x, y = self.__level_up
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=levels, interval=0.1, button='left')

    def action_sell_company(self):
        x, y = self.__sell_company
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=0.1, button='left')
        x, y = self.__sell_confirm
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=3, button='left')

    def action_hire_all(self):
        x, y = self.__hire_all
        self.action_click_girl(0)
        if pyautogui.onScreen(x, y):
            pyautogui.click(x, y, clicks=1, interval=2, button='left')
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
        # print(cur)
        if cur in self.__gray:
            return 1
        if cur in self.__green_and_violet:
            return 2
        return 0

    def looped_level_up(self, number_of_passes=1):
        for i in range(11*number_of_passes):
            self.action_click_girl(i % 11)
            if self.state() == 0:
                self.action_click_girl(i % 11)
                if self.state() == 0:
                    print('loop terminated')
                    return
            pyautogui.sleep(2)
            self.action_click_girl(i % 11)
            while self.state() == 2:
                self.action_level_up()
