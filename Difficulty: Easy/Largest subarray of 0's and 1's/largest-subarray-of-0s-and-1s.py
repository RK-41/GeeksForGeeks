class Solution:
    def maxLen(self, arr):
        # code here
        # 16.01.25 POtd
        ans, sm, n = 0, 0, len(arr)
        pos = {}
        
        for i in range(n):
            sm += (1 if arr[i] == 1 else -1)

            if sm == 0:
                ans = max(ans, i+1)
            
            if sm in pos:
                ans = max(ans, i - pos[sm])
            else:
                pos[sm] = i
                
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    a = list(map(int, input().split()))
    s = Solution().maxLen(a)
    print(s)

# } Driver Code Ends