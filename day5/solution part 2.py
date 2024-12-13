import time

with open("input.txt", 'r') as file:
    nums = list(map(int, file.read().split('\n')))

end = len(nums)
steps = 0
position = 0

start = time.time()
while position >= 0 and position < end:
    jump = nums[position]
    if jump >= 3: nums[position] -= 1
    else: nums[position] += 1
    position += jump
    steps += 1
end = time.time()
print(steps)
print(end - start)