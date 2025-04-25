#User function template for Python 3

class Solution:
    def majorityElement(self, arr):
        #code here
        # 25.04.25 (POTD)
        majPos, count = 0, 1
        
        # Finding majority element position
        for i in range(1, len(arr)):
            if arr[majPos] == arr[i]:
                count += 1
            else:
                count -= 1
            
            if count == 0:
                majPos = i
                count = 1
                
        # Confirming majority
        count = 0
        for i in range(len(arr)):
            if arr[majPos] == arr[i]:
                count += 1
        
        if count > len(arr) - count:
            return arr[majPos]
            
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
from sys import stdin


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]

        obj = Solution()
        print(obj.majorityElement(arr))
        print("~")
        t -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends