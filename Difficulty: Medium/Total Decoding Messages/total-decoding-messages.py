#User function Template for python3
class Solution:
	def countWays(self, digits):
		# Code here
        # 23.03.25 potd
        n = len(digits)
        dp = [-1] * (n)
        
        def solve(i):
            if i >= n:  return 1
            if dp[i] != -1: return dp[i]
            
            if digits[i] == '0':    return 0
            
            take2 = 0
            take1 = solve(i+1)
            
            if i + 1 < n and int(digits[i:i+2]) <= 26:
                take2 = solve(i+2)
            
            dp[i] = take1 + take2
            return dp[i]
            
        return solve(0)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        digits = input()
        ob = Solution()
        ans = ob.countWays(digits)
        print(ans)
        print("~")

# } Driver Code Ends