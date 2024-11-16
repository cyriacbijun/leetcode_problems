def maxProfit(prices) -> int:
        minP = 10000
        profit = 0
        for i in range(len(prices)):
            if(minP > prices[i]):
                minP = prices[i]
            else:
                profit = max(profit, prices[i] - minP)
        return profit