count = 0
with open("input.txt", 'r') as file:
    for line in file:
        password = line.split()
        if len(password) == len(set(password)): count += 1

print(count) 
