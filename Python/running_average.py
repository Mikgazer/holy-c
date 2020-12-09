
# Read a string with digits from the input and convert each number of the string to an integer.
# For your newly created list, calculate the running average according to the following formula:
# A_{i} = (x_{i} + x_{i+1})/2 (_{i} here is meant to indicate that i is a subscript)
# - where x_{i} and x_{i+1} are elements of the original list, A_{i} is the element of the moving average.
# For instance, if your string is 123, an average of 1 and 2 will be 1.5, and an average of 2 and 3 will be 2.5.
# Print the result. Notice that this list will have one less item.

input_numbers = [float(n) for n in input().split(" ")]
average = []
for i in range(len(input_numbers) - 1):
    average.append((input_numbers[i] + input_numbers[i + 1]) / 2)
print(average)

