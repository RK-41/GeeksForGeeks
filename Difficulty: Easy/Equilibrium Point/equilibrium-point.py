# User function Template for python3

class Solution:
    #Function to find equilibrium point in the array.
    def findEquilibrium(self, arr):
        # code here
        # 14.01.25 POTD
        left, right, n = 0, 0, len(arr)
        right = sum(arr)
        
        for i in range(n):
            right -= arr[i]
            
            if left == right:
                return i
            
            left += arr[i]
        
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.findEquilibrium(arr))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends