#User function Template for python3

class Solution:
    def productExceptSelf(self, arr):
        #code here
        # 17.01.25 POTD
        ans, prod, n = [], 1, len(arr)
        
        # Storing left side product
        for a in arr:
            ans.append(prod)
            prod *= a
        
        # Multiplying with right side product
        prod = 1    
        for i in range(n-1, -1, -1):
            ans[i] *= prod
            prod *= arr[i]
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends