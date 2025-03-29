class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        # 29.03.25 potd
        
        import heapq
        pairs = sorted(zip(deadline, profit), key=lambda x: (x[0], -x[1]))
        h, cur = [], 0
        for d, p in pairs:
            if d > cur:
                cur += 1
                heapq.heappush(h, p)
            elif d == cur:
                heapq.heappushpop(h, p)
        return len(h), sum(h)


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq

#Position this line where user code will be pasted.

if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        deadline = list(map(int, input().strip().split()))
        profit = list(map(int, input().strip().split()))

        obj = Solution()
        ans = obj.jobSequencing(deadline, profit)
        print(ans[0], ans[1])
        print("~")
# } Driver Code Ends