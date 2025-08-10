taskCount = int(input())
taskWorked = 0
for _ in range(taskCount):
    petya, vasya, tonya = map(int, input().split())
    count1 = petya + vasya + tonya
    if count1 >= 2:
        taskWorked += 1
print(taskWorked)
