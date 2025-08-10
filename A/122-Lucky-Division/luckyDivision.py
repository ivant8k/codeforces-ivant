lucky_numbers = []

for i in range(1, 1000):
    if all(digit in '47' for digit in str(i)):
        lucky_numbers.append(i)

n = int(input())
if n in lucky_numbers:
    print("YES")
else:
    for lucky in lucky_numbers:
        if n % lucky == 0:
            print("YES")
            break
    else:
        print("NO")