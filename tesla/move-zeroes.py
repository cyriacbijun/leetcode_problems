def move_zeroes(numbers):
    i = 0
    j = 0
    n = len(numbers)
    while(j < n):
        if(numbers[j] != 0 and numbers[i] == 0):
            temp = numbers[i]
            numbers[i] = numbers[j]
            numbers[j] = temp
        if(numbers[i] != 0):
            i += 1
        j += 1
    return numbers

ans = move_zeroes([0,1,0,3,12])

print(ans)