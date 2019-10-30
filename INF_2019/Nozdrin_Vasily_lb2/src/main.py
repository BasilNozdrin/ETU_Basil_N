

def gen_dic(n):
    print("states = {", end='')
    for i in range(n):
        print(
            """
    'q{}': {{
        '0': ('0', 0, 'q{}'),
        '1': ('1', 0, 'q{}'),
        '2': ('2', 0, 'q{}'),
        ' ': (' ', 0, 'q{}'),
        '+': ('+', 0, 'q{}'),
        '-': ('-', 0, 'q{}'),
    }},""".format(i, i, i, i, i, i, i)
        )
    print("}")


states = {
    # reading until '+' or '-'
    'q1': {
        '0': ('0', 1, 'q1'),
        '1': ('1', 1, 'q1'),
        '2': ('2', 1, 'q1'),
        ' ': (' ', 1, 'q1'),
        '+': ('+', 1, 'q2'),
        '-': ('-', 1, 'q5'),
    },

    # reading second arg for sum
    'q2': {
        '0': ('0', -1, 'q8'),
        '1': ('1', -1, 'q3'),
        '2': ('2', -1, 'q4'),
    },
    # +1
    'q3': {
        '0': ('1', 0, 'qn'),
        '1': ('2', 0, 'qn'),
        '2': ('0', -1, 'q3'),
        ' ': ('1', 0, 'qn'),
        '+': ('+', -1, 'q3'),
    },
    # +2
    'q4': {
        '0': ('2', 0, 'qn'),
        '1': ('0', -1, 'q3'),
        '2': ('1', -1, 'q3'),
        ' ': ('2', 0, 'qn'),
        '+': ('+', -1, 'q4'),
    },

    # reading second arg for dif
    'q5': {
        '0': ('0', -1, 'q8'),
        '1': ('1', -1, 'q6'),
        '2': ('2', -1, 'q7'),
    },
    # -1
    'q6': {
        '0': ('2', -1, 'q6'),
        '1': ('0', -1, 'q9'),
        '2': ('1', 0, 'qn'),
        '-': ('-', -1, 'q6'),
    },
    # -2
    'q7': {
        '0': ('1', -1, 'q6'),
        '1': ('2', -1, 'q6'),
        '2': ('0', -1, 'q9'),
        '-': ('-', -1, 'q7'),
    },

    # remove +- if arg is 0
    # +-0
    'q8': {
        '+': ('+', 0, 'qn'),
        '-': ('-', 0, 'qn'),
    },

    # delete 0
    'q9': {
        '0': ('0', 0, 'qn'),
        '1': ('1', 0, 'qn'),
        '2': ('2', 0, 'qn'),
        ' ': (' ', +1, 'q10'),
    },
    'q10': {
        '0': (' ', 1, 'q10'),
        '1': ('1', 0, 'qn'),
        '2': ('2', 0, 'qn'),
        '+': ('+', -1, 'q11'),
        '-': ('-', -1, 'q11'),
    },
    'q11': {
        ' ': ('0', 0, 'qn'),
    },

    # terminal state
    'qn': {}
}


def main():
    line = list(' '*2 + input() + ' '*2)
    position = 0
    state = 'q1'
    while state != 'qn':
        value = line[position]
        new_value, move, next_state = states[state][value]
        line[position], state = new_value, next_state
        position += move
        if position < 0:
            raise IndexError('string index out of range')
    print(''.join(line[2:-2]))


main()
