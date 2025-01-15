# User function Template for python3

class Solution:
    def longestSubarray(self, arr, k):  
        # code here
        # 15.01.25 POTD
        ans = 0
        sumPos = {}
        sm, n = 0, len(arr)
        
        for i in range(n):
            sm += arr[i]
            
            if sm == k:
                ans = i + 1
                
            if (sm - k) in sumPos:
                ans = max(ans, i - sumPos[sm - k])
            
            # Storing the position of first occurrence only
            if sm not in sumPos:
                sumPos[sm] = i
                
        return ans
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        tc -= 1
        print("~")
# } Driver Code Ends