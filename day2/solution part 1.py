
checksum = 0

with open("input.txt", 'r') as file:
    for line in file:
        sequence = list(map(int, line.split('\t')))
        checksum += max(sequence) - min(sequence)

print(checksum)

