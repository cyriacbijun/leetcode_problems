def missingNumber(self, nums) -> int:
    missing = 0
    for num in nums:
        missing ^= num
    for i in range(len(nums) + 1):
        missing ^= i
    return missing
