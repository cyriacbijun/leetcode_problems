def trap_water(heights):
    n = len(heights)
    l =0
    r = n -1
    lMax = 0
    rMax = 0
    total = 0
    while(l < r):
        if(heights[l] < heights[r]):
            if(heights[l] > lMax):
                lMax = heights[l]
            else:
                total += lMax - heights[l]
            l += 1
        else:
            if(heights[r] > rMax):
                rMax = heights[r]
            else:
                total += rMax - heights[r]
            r -= 1
    return total

ans = trap_water([4,2,0,3,2,5])

print(ans)