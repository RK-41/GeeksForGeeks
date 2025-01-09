#User function Template for python3
class Solution:
    def subarraySum(self, arr, target):
        # code here
        # 09.01.25 POTD
        sumPos = {}
        sm, n = 0, len(arr)
        
        for i in range(n):
            sm += arr[i]
            
            if sm == target:
                return [1,i+1]
                
            if (sm - target) in sumPos:
                return [sumPos[sm - target] + 1, i + 1]
                
            sumPos[sm] = i + 1
            
        return [-1]

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        d = int(input().strip())
        ob = Solution()
        result = ob.subarraySum(arr, d)
        print(" ".join(map(str, result)))
        tc -= 1
        print("~")

# } Driver Code Ends