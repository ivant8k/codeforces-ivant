'''University Exam'''

p = int(input())

if p < 18:
    print("Failed")
else:
    t = int(input())
    total = p + t
    if total >= 60:
        print("Passed")
    else:
        print("Failed")