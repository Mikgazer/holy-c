
# Write a program that takes three strings as input and then constructs and prints a nested list from them.
# The first string as a first element, a list containing only second string as a second element
# - and a list containing another list containing a third string as a third element.
str_1 = input()
str_2 = input()
str_3 = input()
basic_list = [str_1, str_2, str_3]
new_list = []
for a, _ in enumerate(basic_list):
    element = basic_list[a]
    for _ in range(a):
        element = [element]
    new_list.append(element)
print(new_list)
# enumerate works with an index and an iterable. The index iterates on the iterable value
# i.e index i iterates on a list inside a list

# https://www.programiz.com/python-programming/methods/built-in/enumerate
# How does enumerate work?
grocery = ['bread', 'milk', 'butter']
enumerateGrocery = enumerate(grocery)

print(type(enumerateGrocery))

# converting to list
print(list(enumerateGrocery))

# changing the default counter
enumerateGrocery = enumerate(grocery, 10)
print(list(enumerateGrocery))