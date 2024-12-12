with open("input.txt", 'r') as file:
    content = file.read()


total_sum = 0
length = len(content)     

for i in range(length):

    if content[i] == content[(i + 1) % length]:
        total_sum += int(content[i])

print(total_sum)