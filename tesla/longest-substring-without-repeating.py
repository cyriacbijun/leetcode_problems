def lengthOfLongestSubstring( s: str) -> int:
    n = len(s)
    maxlen = 0
    ch_dict = {}
    l,r = 0,0
    for r in range(n):
        if(s[r] not in ch_dict):
            maxlen = max(maxlen, r-l + 1)
        else:
            if l <= ch_dict[s[r]]:
                l = ch_dict[s[r]] + 1
            else:
                maxlen = max(maxlen, r-l + 1)
        ch_dict[s[r]] = r  
    return maxlen