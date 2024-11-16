from collections import Counter

def count_balloons(txt):
    text_count = Counter(txt)
    balloon_count = Counter("balloon")
    counts = []
    for key, value in balloon_count.items():
        counts.append(text_count[key]//value)
    return min(counts)

print(count_balloons("loonbalxballpoon"))