from collections import Counter
from heapq import nlargest

def get_elements(items,k):
    count = Counter(items)
    freq = nlargest(k, count.items(),key=lambda item:item[1] )
    return [x[0] for x in freq]

ans = get_elements([1,1,1,2,2,3],2)

print(ans)