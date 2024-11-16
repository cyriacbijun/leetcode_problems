def spiralMatrixIII(rows: int, cols: int, rStart: int, cStart: int):
    dir = [[0,1],[1,0],[0,-1],[-1,0]]
    step = 1
    ans = []
    r,c = rStart, cStart
    i = 0
    while(len(ans) < rows * cols):
        for _ in range(2):
            for _ in range(step):
                if 0<= r < rows and 0<= c < cols:
                    ans.append([r,c])
                r,c = r + dir[i][0], c + dir[i][1]
            i = (i+1) % 4
        step += 1
    return ans

ans = spiralMatrixIII( rows = 5, cols = 6, rStart = 1, cStart = 4)

print(ans)
