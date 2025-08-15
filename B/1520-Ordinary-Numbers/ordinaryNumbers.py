def count_ordinary_numbers(n):
    """
    Count ordinary numbers up to n using mathematical approach.
    Ordinary numbers are: 1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,...
    """
    if n == 0:
        return 0
    
    count = 0
    digits = len(str(n))
    
    # Count all ordinary numbers with fewer digits than n
    for d in range(1, digits):
        count += 9  # 9 ordinary numbers for each digit length (1,11,111... to 9,99,999...)
    
    # Count ordinary numbers with same number of digits as n
    for digit in range(1, 10):
        # Generate ordinary number with 'digits' length using 'digit'
        ordinary_num = int(str(digit) * digits)
        if ordinary_num <= n:
            count += 1
        else:
            break
    
    return count

t = int(input())

for _ in range(t):
    n = int(input())
    print(count_ordinary_numbers(n))
