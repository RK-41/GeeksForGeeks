from typing import List


class Solution:
    def maximumProfit(self, prices) -> int:
        # code here
        # 21.11.24 POTD
        profit, i, n = 0, 1, len(prices)
        
        while i<n:
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1];
            i += 1
                
        return profit


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.maximumProfit(arr)
        print(res)

# } Driver Code Ends