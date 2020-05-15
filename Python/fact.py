def fact_to_dec (str):
    n = 1
    n_fact = 1
    result = 0
    while len(str):
        result += int(str[-1])*n_fact
        n += 1
        n_fact *= n
        str = str[:-1]
    return result


def dec_to_fact (arg):
    result = ""
    n = 2
    while arg:
        result += str(arg % n)
        arg //= n
        n += 1

    return result[::-1]
