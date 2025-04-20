#User function Template for python3
class Solution:
    def findDuplicate(self, arr):
        #code here
        # 20.04.25 POTD
        ans = len(arr)
        
        for i in range(len(arr)):
            ans ^= arr[i]
            ans ^= (i + 1)
        
        return ans

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        print(ob.findDuplicate(arr))
        print("~")

# } Driver Code Ends