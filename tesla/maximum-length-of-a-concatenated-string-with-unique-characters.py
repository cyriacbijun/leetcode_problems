from collections import Counter
def maxLength(arr):
    charSet = set()
    n = len(arr)

    def overlap(charSet, s):
        c = Counter(charSet) + Counter(s)
        return max(c.values())>1
    
    def backtrack(i):
        if i == n:
            return len(charSet)
        res = 0
        if not overlap(charSet, arr[i]):
            for c in arr[i]:
                charSet.add(c)
            res = backtrack(i+1)
            for c in arr[i]:
                charSet.remove(c)
        return max(res, backtrack(i+1))
    return backtrack(0)
