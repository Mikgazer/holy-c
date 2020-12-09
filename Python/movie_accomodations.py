
def movie_theater_accommodation(number_of_halls, capacity, number_of_viewers):
    can_hold = ((number_of_halls * capacity) >= number_of_viewers)
    if can_hold:
        print("True")
    else:
        print("False")


print("Usage: number of halls, capacity, number of viewers.")
n_h = int(input())
cap = int(input())
n_m = int(input())
movie_theater_accommodation(n_h, cap, n_m)
