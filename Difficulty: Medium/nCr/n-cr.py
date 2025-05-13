class Solution:
    def nCr(self, n, r):
        # code here
        # 13.05.25 (potd)
        if n == r:  return 1
        if n < r:   return 0
        
        dp = [[-1] * (n+1) for _ in range(n+1)]
        mod = 10**9+7
        
        for i in range(n+1):
            for j in range(i+1):
                if j == 0 or i == j:
                    dp[i][j] = 1
                else:
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod
                    
        return dp[n][r]

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        r = int(input())
        ob = Solution()
        print(ob.nCr(n, r))
        print("~")
# } Driver Code Ends