def fizzbuzz(num, n, m):
    for index in range(1, num):
        if index % n == 0 and index % m == 0:
            print("Fizzbuzz")
        elif index % n == 0:
            print("Fizz")
        elif index % m == 0:
            print("buzz")
        else:
            print(index)
    exit(0)

print("Usage: times, n, m. Type 'exit' to exit.\n")
while True:
    input_str = input()
    if input_str == "exit":
        exit(0)
    numbers = (input_str.split(sep=","))
    if len(numbers) != 3:
        print("Please insert three valid numbers.")
    else:
        fizzbuzz(int(numbers[0]), int(numbers[1]), int(numbers[2]))
