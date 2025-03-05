#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    def longestStringChain(self, words):
        # Code here
        # 05.03.25 potd
        ans = 0
        strings = sorted(words, key = len)
        dp = {}
        
        for w in strings:
            dp[w] = 1
            
            for i in range(len(w)):
                pre = w[:i] + w[i+1:]
                
                if pre in dp:
                    dp[w] = max(dp[w], dp[pre] + 1)
            
            ans = max(ans, dp[w])
            
        return ans
 

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range (t):
        words = input().split()
        ob = Solution()
        res = ob.longestStringChain(words)
        print(res)
        print("~")
# } Driver Code Ends