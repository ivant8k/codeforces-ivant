t = int(input())

for _ in range(t):
    n = int(input())
    
    max_sum = 0
    best_x = 2
    
    for x in range(2, n + 1):
        k = n // x
        current_sum = x * k * (k + 1) // 2
        
        if current_sum > max_sum:
            max_sum = current_sum
            best_x = x
    
    print(best_x)