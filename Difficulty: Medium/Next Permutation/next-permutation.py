#User function Template for python3

class Solution:
    def reverse(self, arr, s, e):
        while s<e:
            arr[s], arr[e] = arr[e], arr[s]
            s += 1
            e -= 1
        
    def nextPermutation(self, arr):
        # code here
        # 19.11.24 potd
        n = len(arr)
        idx = n-2
        
        while idx>=0 and arr[idx]>=arr[idx+1]:
            idx -= 1
        if idx>=0:
            i = n-1
            while arr[i]<=arr[idx]:
                i -= 1
            arr[idx], arr[i] = arr[i], arr[idx]
            
        self.reverse(arr, idx+1, n-1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        N = len(arr)
        for i in range(N):
            arr[i] = int(arr[i])

        ob = Solution()
        ob.nextPermutation(arr)
        for i in range(N):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends