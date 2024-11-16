def groupAnagrams(self, strs):
    word_dict = {}
    ans = []
    for word in strs:
        sr_word = "".join(sorted(word))
        if sr_word in word_dict:
            word_dict[sr_word].append(word)
        else:
            word_dict[sr_word] = [word]
    for _,value in word_dict.items():
        ans.append(value)
    return ans