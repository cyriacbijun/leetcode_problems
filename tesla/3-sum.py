def three_sum(numbers):
    number_dict = {}
    n = len(numbers)
    for i in range(n):
        number_dict[numbers[i]] = i

    sol = set()
    for i in range(n):
        for j in range(i+1,n):
            req = -(numbers[i] + numbers[j])
            if(req in number_dict) and number_dict[req] != i and number_dict[req] != j:
                sol.add(tuple(sorted([numbers[i],numbers[j],req])))
    return sol

ans = three_sum([0,0,0])

print(ans)