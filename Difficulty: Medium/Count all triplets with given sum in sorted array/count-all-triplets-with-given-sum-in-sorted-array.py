from collections import defaultdict
class Solution:
    def countTriplets(self, arr, target):
        # code here
        # 04.01.25 pOtD
        ans = 0
        i, n = 0, len(arr)
        mp = defaultdict(int)
        
        for a in arr:
            mp[a] += 1
        
        for i in range(n):
            mp[arr[i]] -= 1
            
            for k in range(0,i):
                third = target - arr[i] - arr[k]
                ans += mp[third]

        return ans

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input())
        ob = Solution()
        ans = ob.countTriplets(arr, target)
        print(ans)
        print("~")
# } Driver Code Ends