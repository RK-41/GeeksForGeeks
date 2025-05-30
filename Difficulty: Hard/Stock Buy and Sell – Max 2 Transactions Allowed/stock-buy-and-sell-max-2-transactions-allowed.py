class Solution:
    def maxProfit(self, prices):
        # code here
        # 20.03.25 potd
        if len(prices) <= 1:    return 0
        
        n = len(prices)
        dp = [[0] * n for _ in range(3)]
        
        for i in range(1, 3):
            diff = -prices[0]
            
            for j in range(1, n):
                dp[i][j] = max(dp[i][j-1], prices[j] + diff)
                diff = max(diff, dp[i-1][j] - prices[j])
                
        return dp[2][n-1]

#{ 
 # Driver Code Starts
#Initial template for Python 3
import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxProfit(arr))
        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends