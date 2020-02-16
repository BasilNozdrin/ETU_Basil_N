# -*- coding: utf-8 -*-


class HouseScheme:
    def __init__(self, amount_of_rooms, house_area, combined_bathroom):
        if (amount_of_rooms < 0) or (house_area < 0) or (not isinstance(combined_bathroom, bool)):
            raise ValueError('Invalid value')
        self.amount_of_rooms = amount_of_rooms
        self.house_area = house_area
        self.combined_bathroom = combined_bathroom


class CountryHouse(HouseScheme):
    def __init__(self, amount_of_rooms, house_area, combined_bathroom, amount_of_floors, area):
        super().__init__(amount_of_rooms, house_area, combined_bathroom)
        if (amount_of_floors < 0) or (area < 0):
            raise ValueError('Invalid value')
        self.amount_of_floors = amount_of_floors
        self.area = area

    def __str__(self):
        return 'Country House: Количество жилых комнат {}, Жилая площадь {}, Совмещенный санузел {}, Количество ' \
               'этажей {}, Площадь участка {}.'.format(self.amount_of_rooms, self.house_area, self.combined_bathroom,
                                                       self.amount_of_floors, self.area)

    def __eq__(self, o):
        """
        :type o: CountryHouse
        """
        return (self.house_area == o.house_area) and (self.area == o.area) and \
               (abs(self.amount_of_floors - o.amount_of_floors) <= 1)


class Apartment(HouseScheme):
    def __init__(self, amount_of_rooms, house_area, combined_bathroom, floor, windows_direction):
        super().__init__(amount_of_rooms, house_area, combined_bathroom)
        if (floor < 1) or (floor > 15) or (windows_direction not in 'NSWE'):
            raise ValueError('Invalid value')
        self.floor = floor
        self.windows_direction = windows_direction

    def __str__(self):
        return 'Apartment: Количество жилых комнат {}, Жилая площадь {}, Совмещенный санузел {}, Этаж {}, ' \
               'Окна выходят на {}.'.format(self.amount_of_rooms, self.house_area, self.combined_bathroom,
                                            self.floor, self.windows_direction)


class CountryHouseList(list):
    def __init__(self, name: str):
        super().__init__()
        self.name = name

    def append(self, p_object):
        if not isinstance(p_object, CountryHouse):
            raise TypeError('Invalid type {}'.format(type(p_object)))
        super().append(p_object)

    def total_square(self):
        return sum(map(lambda x: x.house_area, self))


class ApartmentList(list):
    def __init__(self, name: str):
        super().__init__()
        self.name = name

    def extend(self, iterable):
        super().extend(filter(lambda x: isinstance(x, Apartment), iterable))

    def floor_view(self, floors, directions):
        for x in filter(lambda flat: (flat.floor in range(floors[0], floors[1] + 1)) and (
                                        flat.windows_direction in directions), self):
            print("{}: {}".format(x.windows_direction, x.floor))
