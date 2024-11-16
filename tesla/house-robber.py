def reward(nums):
    n = len(n)
    dp = [0] * n
    dp[0] = nums[0]
    dp[1] = nums[1]
    reward = 0
    for i in range(2,len(nums)):
        reward += max(nums[i] + dp[i-2], dp[i-1])
        dp[i] = reward
    return reward