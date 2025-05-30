#User function Template for python3
class Solution:
    def countWays(self, expr):
        # code here
        # 25.03.25 potd
        n = len(expr)
        dp = [[[0]*2 for _ in range(n)] for _ in range(n)]
        
        for i in range(n-1, -1, -2):
            for j in range(i, n, 2):
                if i == j:
                    dp[i][j][0] = int(expr[i] == 'F')
                    dp[i][j][1] = int(expr[i] == 'T')
                else:
                    for k in range(i+1, j, 2):
                        match expr[k]:
                            case '&':
                                dp[i][j][1] += dp[i][k-1][1]*dp[k+1][j][1]
                                dp[i][j][0] += dp[i][k-1][0]*dp[k+1][j][0]
                                dp[i][j][0] += dp[i][k-1][1]*dp[k+1][j][0]
                                dp[i][j][0] += dp[i][k-1][0]*dp[k+1][j][1]
                            case '|':
                                dp[i][j][1] += dp[i][k-1][1] * dp[k+1][j][1]    
                                dp[i][j][1] += dp[i][k-1][0] * dp[k+1][j][1]
                                dp[i][j][1] += dp[i][k-1][1] * dp[k+1][j][0]
                                dp[i][j][0] += dp[i][k-1][0] * dp[k+1][j][0]
                            case '^':
                                dp[i][j][1] += dp[i][k-1][0] * dp[k+1][j][1] + dp[i][k-1][1] * dp[k+1][j][0]
                                dp[i][j][0] += dp[i][k-1][0] * dp[k+1][j][0] + dp[i][k-1][1] * dp[k+1][j][1]
        return dp[0][-1][1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        print(Solution().countWays(s))
        print("~")

# } Driver Code Ends