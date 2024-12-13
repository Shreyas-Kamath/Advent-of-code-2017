count = 0

def check(passphrases: list[str]) -> bool:
    seen = set()
    for phrase in passphrases:
        sorted_word = ''.join(sorted(phrase))
        if sorted_word in seen:
            return False
        seen.add(sorted_word)
    return True


with open("input.txt", 'r') as file:
    for line in file:
        passphrases = list(line.split())
        if check(passphrases):
            count += 1

print(count)
