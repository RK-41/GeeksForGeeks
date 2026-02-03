class Solution:
    def maxProfit(self, prices):
        # code here
        # 03.02.26 (potd)
        ans, n = 0, len(prices)
        mxPriceRTL = [0]*n
        mx = prices[-1]
        
        # Find max element up to pos i from right to left
        for i in range(n-1,0,-1):
            mx = max(mx, prices[i])
            mxPriceRTL[i] = mx
            
        # Find max profit
        for i in range(n-1):
            # Diff b/w curr price and max price to its right
            diff = mxPriceRTL[i+1] - prices[i]
            ans = max(ans, diff)
        
        return ans


