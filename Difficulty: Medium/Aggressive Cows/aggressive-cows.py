#User function Template for python3
class Solution:
    def aggressiveCows(self, stalls, k):
        # 17.12.24 poTD
        
        def canPlaceCows(stalls, dist, k):
            n = len(stalls)
            count = 1
            prevPos = stalls[0]
            
            for i in range(1,n):
                if stalls[i] - prevPos >= dist:
                    count += 1
                    prevPos = stalls[i]
                
                if count >= k:
                    return True
                    
            return False
            
        
        stalls.sort()
        ans, start, end = 0, 1, stalls[-1] - stalls[0]
        while start <= end:
            mid = (start + end)//2
            
            if canPlaceCows(stalls, mid, k):
                start = mid + 1
                ans = mid
            else:
                end = mid - 1
                
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.aggressiveCows(A, D)
        print(ans)
        print("~")
# } Driver Code Ends