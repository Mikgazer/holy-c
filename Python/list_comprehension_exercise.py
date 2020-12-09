
# Given a numeric sequence, create a list in which each number will be a digit from this input string.
# Then use this list to calculate the running total, or cumulative sum.
# Essentially, it's a new list of partial sums that gets updated every time a new element appears.
def iterate_list(number_list):
    new_list = []
    for index in range(len(number_list)):
        new_list.append(sum(number_list[0:index + 1]))
    return new_list


# Remember that slicing acts this way "[a,b)", 0:x -> x elements

print("Insert a number of digits in any order, but not separated by space or any other characters.")
numbers = [int(n) for n in input()]
sum_list = iterate_list(numbers)

print(sum_list)
