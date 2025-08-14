'''Make Them Happy'''

n, x = map(int, input().split())
a = list(map(int, input().split()))

count = [0] * x
for num in a:
    count[num % x] += 1

happy = 0

if count[0] > 0:
    happy += count[0] * (count[0] - 1) // 2

for r in range(1, (x + 1) // 2):
    complement = x - r
    if r != complement:
        if (r * complement) % x == 0:
            happy += count[r] * count[complement]

if x % 2 == 0:
    r = x // 2
    if (r * r) % x == 0:
        happy += count[r] * (count[r] - 1) // 2

print(happy)