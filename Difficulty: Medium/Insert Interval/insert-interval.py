#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def insertInterval(self, intervals, newInt):
        # Code here
        # 09.12.24 POtD
        ans = []
        n, i = len(intervals), 0
        
        while i<n and intervals[i][1] < newInt[0]:
            ans.append(intervals[i])
            i += 1
            
        
        while i<n and newInt[1] >= intervals[i][0]:
            newInt[0] = min(newInt[0], intervals[i][0])
            newInt[1] = max(newInt[1], intervals[i][1])
            i += 1
        
        ans.append(newInt)
        
        while i<n:
            ans.append(intervals[i])
            i += 1
            
        return ans
            

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        newEvent = list(map(int, input().split()))
        ob = Solution()
        res = ob.insertInterval(intervals, newEvent)
        print('[', end = '')
        for i in range(len(res)):
            print('[', end = '')
            print(str(res[i][0])+','+str(res[i][1]), end = '')
            print(']', end = '')
            if i < len(res)-1:
                print(',', end='')
        print(']')
        print("~")
# } Driver Code Ends