class Solution:
    def subarrayXor(self, arr, k):
        # code here
        # 03.01.25 POtd
        ans, xor = 0, 0
        xorMap = {}
        xorMap[0] = 1
        
        for a in arr:
            xor ^= a
            ans += xorMap.get(xor^k,0)
            xorMap[xor] = xorMap.get(xor,0) + 1
            
        return ans


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")

# } Driver Code Ends