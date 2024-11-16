def process(moves):
    n = 3
    row = [0] * n
    col = [0] * n
    d1 = 0
    d2 = 0
    player = 1
    for r,c in (moves):
        row[r] += player
        col[c] += player
        if(r == c):
            d1 += player
        if(r == 2-c):
            d2 += player
        if abs(row[r]) == n or abs(col[c]) ==n or abs(d1) == n or abs(d2) == n:
            if player == 1:
                return "A"
            else:
                return "B"
        player *= -1
    if(len(moves) == n*n):
        return "Draw"
    else:
        return "Pending"
    
ans = process([[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2]])

print(ans)