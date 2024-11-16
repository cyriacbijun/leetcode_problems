def isPalindrome(self, s: str) -> bool:
    s = [ch.lower() for ch in s if ch.isalnum()]
    for i in range(len(s)//2):
        j = -i - 1
        if(s[i] != s[j]):
            return False
    return True