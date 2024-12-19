#User function Template for python3
class Solution:
    def kthMissing(self, arr, k):
        # code here
        # 19.12.24 potd
        lo, hi = 0, len(arr)-1
        
        while lo <= hi:
            mid = (lo + hi)//2
            missing = arr[mid] - (mid + 1)
            if missing < k:
                lo = mid + 1
            else:
                hi = mid - 1
                
        return k + hi + 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.kthMissing(A, D)
        print(ans)
        print("~")

# } Driver Code Ends