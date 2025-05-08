#User function Template for python3

class Solution:
    def findMissing(self, arr):
        # code here
        # 08.05.25 POTD
        n = len(arr)
        rev = False
        
        if arr[0] > arr[1]:
            arr = arr[::-1]
            rev = True
            
        d = min(arr[1]-arr[0], arr[-1]-arr[-2])
        
        if n == 2:
            return arr[0] - d if rev else arr[1] + d
        
        
        for i in range(1,n):
            if arr[i] - arr[i-1] > d:
                return arr[i-1] + d
        
        return arr[0] - d if rev else arr[-1] + d


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import sys
import math


def main():
    input = sys.stdin.read
    data = input().strip().split('\n')

    t = int(data[0])
    solution = Solution()

    for i in range(1, t + 1):
        arr = list(map(int, data[i].split()))
        print(solution.findMissing(arr))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends