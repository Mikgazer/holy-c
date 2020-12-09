
# Nested lists comprehensions examples
some_list = [0, [1, [2, 3]]]
print(some_list)

# original list
school = [["Mary", "Jack", "Tiffany"],
          ["Brad", "Claire"],
          ["Molly", "Andy", "Carla"]]

student_list = []
for class_group in school:
    for student in class_group:
        student_list.append(student)

print(school)
print(student_list)
