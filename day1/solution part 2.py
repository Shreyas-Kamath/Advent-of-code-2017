with open("input.txt", 'r') as file:
    content = file.read()


total_sum = 0
length = len(content)     

for i in range(length):
    lhs = content[i]
    rhs = content[(i + length//2) % length]
    if lhs == rhs:
        total_sum += int(content[i])

print(total_sum)