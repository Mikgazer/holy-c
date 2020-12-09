
def sleeping_time(min_h, max_h, time):
    if time < min_h:
        return "Deficiency"
    elif time > max_h:
        return "Excess"
    else:
        return "Normal"


min_hours = float(input())
max_hours = float(input())
time_slept = float(input())
result = sleeping_time(min_hours, max_hours, time_slept)
print(result)
