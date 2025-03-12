#Back-end complete function Template for Python 3

class Solution:
    def minCostClimbingStairs(self, cost):
        #Write your code here
        # 12.03.25 POTD
        n = len(cost)
        dp = [-1] * (n+1)
        
        def solve(i):
            if i >= n:
                return 0
            
            if dp[i] != -1:
                return dp[i]
                
            dp[i] = min(solve(i+1), solve(i+2)) + cost[i]
            
            return dp[i]
            
        return min(solve(0), solve(1))
            


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))  # Input array
    obj = Solution()
    res = obj.minCostClimbingStairs(arr)
    print(res)
    print("~")

# } Driver Code Ends