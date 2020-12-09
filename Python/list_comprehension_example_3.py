
# Create a list of words from the text below that are shorter than or equal to the input value. Print the new list.
text = [["Glitch", "is", "a", "minor", "problem", "that", "causes", "a", "temporary", "setback"],
        ["Ephemeral", "lasts", "one", "day", "only"],
        ["Accolade", "is", "an", "expression", "of", "praise"]]

word_length = int(input())
word_list = []
for words in text:
    for word in words:
        if len(word) <= word_length:
            word_list.append(word)
print(word_list)

# an other possible solution
output = [word for world_index in text for word in world_index if len(word) <= word_length]
print(output)
