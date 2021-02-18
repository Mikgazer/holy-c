def fizzbuzz(start, end, n, m):
    for i in range(start, end):
        if i % n == 0 and i % m == 0:
            print("Fizzbuzz")
        elif i % n == 0:
            print("Fizz")
        elif i % m == 0:
            print("buzz")
        else:
            print(i)
    exit(0)

print("Usage: 'start, end, n, m'. Type 'exit' to exit.\n")
while True:
    input_str = input()
    if input_str == "exit":
        exit(0)
    numbers = (input_str.split(sep=","))
    if len(numbers) != 4:
        print("Please insert four valid numbers.")
    else:
        fizzbuzz(int(numbers[0]), int(numbers[1]), int(numbers[2]), int(numbers[3]))
