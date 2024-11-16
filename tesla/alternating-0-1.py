def min_operation(s):
    start_0 = 0
    start_1 = 0
    odd = True
    for c in s:
        if odd:
            if c == '0':
                start_1 += 1
            else:
                start_0 += 1
        else:
            if c == '1':
                start_1 += 1
            else:
                start_0 += 1
        odd = not odd
    return min(start_0,start_1)
        
ans = min_operation("1111")

print(ans)