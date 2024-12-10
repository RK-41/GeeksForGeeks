#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def minRemoval(self, intervals):
        # Code here
        # 10.12.24 potd
        intervals.sort(key=lambda x: x[1])
        ans, prevEnd = 0, -1
        
        for interval in intervals:
            if interval[0] < prevEnd:
                ans += 1
            else:
                prevEnd = interval[1]
                
        return ans

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        ob = Solution()
        res = ob.minRemoval(intervals)
        print(res)
        print("~")
# } Driver Code Ends