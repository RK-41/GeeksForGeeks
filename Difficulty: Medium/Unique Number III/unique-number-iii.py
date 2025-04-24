#User function Template for python3

class Solution:
    def getSingle(self, arr):
        # code here 
        # 24.04.25 POTD
        fr = {}
        
        for x in arr:
            fr[x] = fr.get(x, 0) + 1
        
        for x in fr:
            if fr[x] == 1:
                return x

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSingle(arr)
        print(ans)
        print("~")
# } Driver Code Ends