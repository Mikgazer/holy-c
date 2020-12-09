
# Python3 program to convert string
# from camel case to snake case
from functools import reduce


def change_case(test_str):
    res = [test_str[0].lower()]
    for c in test_str[1:]:
        if c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            res.append('_')
            res.append(c.lower())
        else:
            res.append(c)

    return ''.join(res)


# The join() method takes all items in an iterable and joins them into one string.
# A string must be specified as the separator.
# The lstrip() method removes any leading characters (space is the default leading character to remove)
# leading as in starting characters, so for example: _banana becomes banana where _ is the lstrip parameter
# "   banana" becomes "banana" where space is the lstrip parameter as well as the default parameter.
def change_case_comprehension(test_str):
    return ''.join('_' + i.lower() if i.isupper() else i for i in test_str).lstrip('_')


def change_case_lambda(test_str):
    return reduce(lambda x, y: x + ('_' if y.isupper() else '') + y, test_str).lower()


print("Insert a string to be converted from camel case to snake case: ", end="")
user_str = input()
print(change_case(user_str))
print(change_case_comprehension(user_str))
print(change_case_lambda(user_str))
