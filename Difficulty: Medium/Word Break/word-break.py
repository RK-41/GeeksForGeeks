class Solution:
    def wordBreak(self, s, dictionary):
        # code here
        # 26.03.25 potd
        mxLen = max(len(item) for item in dictionary)
        words = set(dictionary)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        
        for i in range(1, n+1):
            end = max(-1, i-1-mxLen)
            
            for j in range(i-1, end, -1):
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    break
            
        return dp[n]

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    test_case = int(input())

    for _ in range(test_case):
        s = input().strip()
        dictionary = input().strip().split()
        ob = Solution()
        res = ob.wordBreak(s, dictionary)
        if res:
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends