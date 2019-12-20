# -*- coding:utf-8 -*-


class Node:
    """
    Поля:
    __data      # данные, приватное поле
    __prev__    # ссылка на предыдущий элемент списка
    __next__    # ссылка на следующий элемент списка
    """
    def __init__(self, data, prev=None, next_=None):
        self.__data = data  # данные, приватное поле
        self.__prev__ = prev  # ссылка на предыдущий элемент списка
        self.__next__ = next_  # ссылка на следующий элемент списка

    def get_data(self):  # метод возвращает значение поля __data.
        return self.__data

    def __str__(self):
        prev = self.__prev__.get_data() if self.__prev__ is not None else "None"
        next_ = self.__next__.get_data() if self.__next__ is not None else "None"
        return 'data: {}, prev: {}, next: {}'.format(self.__data, prev, next_)

    def set_next(self, next_):
        if self is not None:
            self.__next__ = next_

    def get_next(self):
        if self is not None:
            return self.__next__

    def set_prev(self, prev):
        if self is not None:
            self.__prev__ = prev

    def get_prev(self):
        if self is not None:
            return self.__prev__


class LinkedList:
    """
    Класс, который описывает связный двунаправленный список.
    Класс LinkedList должен иметь 3 поля:
    __length      # длина списка
    __first__     # данные первого элемента списка
    __last__      # данные последнего элемента списка
    """
    def __init__(self, first=None, last=None):
        if first is None:
            if last is not None:
                raise ValueError("invalid value for last")
            # LinkedList[len = 0, [prev: None, next: None, data: first]]
            else:
                self.__length = 0
                self.__first__ = None
                self.__last__ = None
        else:
            # LinkedList[len = 1, [prev: None, next: None, data: first]]
            if last is None:
                self.__length = 1
                self.__first__ = Node(first)
                self.__last__ = self.__first__
            # LinkedList[len = 2, [prev: None, next: last, data: first; prev: first, next: None, data: last]]
            else:
                self.__length = 2
                self.__first__ = Node(first)
                self.__last__ = Node(last, prev=self.__first__)
                self.__first__.set_next(self.__last__)

    def __len__(self):
        return self.__length

    def append(self, element):
        if element is not None:
            new_node = Node(element, prev=self.__last__)
            if self.__length != 0:
                self.__last__.set_next(new_node)
                self.__last__ = new_node
            else:
                self.__first__ = new_node
                self.__last__ = new_node
            self.__length += 1

    def __str__(self):
        if self.__length == 0:
            return 'LinkedList[]'

        length = 'length = ' + str(self.__length)
        elements = []
        current_node = self.__first__
        while current_node is not None:
            elements.append(current_node)
            current_node = current_node.get_next()
        elements = map(str, elements)
        return 'LinkedList[' + length + ', [' + '; '.join(elements) + ']' + ']'

    def pop(self):
        if self.__length == 0:
            raise IndexError("LinkedList is empty!")
        self.__length -= 1
        self.__last__ = self.__last__.get_prev()
        self.__last__.set_next(None)

    def popitem(self, element):
        if self.__length == 0:
            raise KeyError(f'{element} doesn\'t exist!')
        current_node = self.__first__
        new_len = self.__length
        while current_node is not None:
            if current_node.get_data() == element:  # prev -- element -- next
                new_len -= 1
                prev = current_node.get_prev()
                if prev is None:
                    self.__first__ = current_node.get_next()
                else:
                    prev.set_next(current_node.get_next())
                next_ = current_node.get_next()
                if next_ is None:
                    self.__last__ = current_node.get_prev()
                else:
                    next_.set_prev(current_node.get_prev())
                break
            current_node = current_node.get_next()
        if new_len == self.__length:
            raise KeyError(f'{element} doesn\'t exist!')
        self.__length = new_len

    def clear(self):
        self.__length = 0
        self.__first__ = None
        self.__last__ = None


linked_list = LinkedList()
print(linked_list)  # LinkedList[]
print(len(linked_list))  # 0

linked_list.append(10)
print(linked_list)  # LinkedList[length = 1, [data: 10, prev: None, next: None]]
print(len(linked_list))  # 1

linked_list.append(20)
print(linked_list)  # LinkedList[length = 2, [data: 10, prev: None, next: 20; data: 20, prev: 10, next: None]]
print(len(linked_list))  # 2

linked_list.popitem(5)
print(linked_list)  # LinkedList[length = 1, [data: 10, prev: None, next: None]]
print(len(linked_list))  # 1
