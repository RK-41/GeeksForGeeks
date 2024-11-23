#User function Template for python3

class Solution:
    def getMinDiff(self,k, arr):
        # code here
        # 23.11.24 Potd
        arr.sort()
        
        ans = arr[-1] - arr[0]
        n = len(arr)
        
        for i in range(1,n):
            mx = max(arr[-1]-k, arr[i-1]+k)
            mn = min(arr[0]+k, arr[i]-k)
            
            ans = min(ans, mx-mn)
            
        return ans
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.getMinDiff(k, arr)
        print(res)
        print("~")

# } Driver Code Ends