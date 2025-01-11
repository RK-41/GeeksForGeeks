#User function Template for python3

class Solution:
    def longestUniqueSubstr(self, s):
        # code here
        # 11.01.25 POTD
        ans, curr = 0, 0
        leftBound, i, n = -1, 0, len(s)
        lastPos = {}
        
        while i<n:
            if lastPos.get(s[i], -2) < leftBound:
                curr += 1
            else:
                ans = max(ans, curr, i-lastPos[s[i]])
                curr = i - lastPos[s[i]]
                leftBound = lastPos[s[i]]
    
            lastPos[s[i]] = i
            i += 1
        
        ans = max(ans, curr) 
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        ans = solObj.longestUniqueSubstr(s)

        print(ans)

        print("~")
# } Driver Code Ends