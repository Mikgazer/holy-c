old_list = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
list_1 = [x for x in old_list if x % 2 == 0]
list_2 = [x for x in old_list if x >= 8]
list_3 = [x * 2 for x in old_list if x < 13]
list_4 = [x * 2 for x in old_list if x % 2 == 1]
list_5 = [x * 2 for x in old_list]

# example list
# nums = [x * 2 for x in range(11) if x % 2 == 1]

# work with a list from this variable
print("Insert any number digits: ", end="")
numbers = [int(n) for n in input()]
# change the next two lines
less_than_5 = [x for x in numbers if x < 5]
greater_than_5 = [x for x in numbers if x > 5]

# printing your results
# print(nums)
print(less_than_5)
print(greater_than_5)
