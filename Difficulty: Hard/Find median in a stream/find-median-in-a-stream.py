
class Solution:
    def getMedian(self, arr):
        # 20.02.25 potd
        import heapq
        
        ans, up, down = [], [], []
        
        for x in arr:
            x = heapq.heappushpop(up, x)
            x = -heapq.heappushpop(down, -x)
            
            if len(up) == len(down):
                ans.append(x)
                heapq.heappush(up, x)
            elif len(up) > len(down):
                ans.append((up[0] + x)/2)
                heapq.heappush(down, -x)
            else:
                ans.append((-down[0] + x)/2)
                heapq.heappush(up, x)
                
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.getMedian(nums)
        print(" ".join(f"{x:.1f}" for x in ans))


if __name__ == "__main__":
    main()

# } Driver Code Ends