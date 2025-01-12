
class Solution:
    def maxWater(self, arr):
        # code here
        # 12.01.25 (potd)
        # Approach: Two Pointer Technique
        ans = 0
        left, right = 0, len(arr)-1
        leftBlock, rightBlock = arr[0], arr[-1]
        
        # Traverse the array while moving opposite from 
        #   the side having smaller Block
        while left <= right:
            if leftBlock < rightBlock:
                if leftBlock < arr[left]:
                    leftBlock = arr[left]
                else:
                    ans += leftBlock - arr[left]
                    left += 1
            else:
                if rightBlock < arr[right]:
                    rightBlock = arr[right]
                else:
                    ans += rightBlock - arr[right]
                    right -= 1
        
        return ans


#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends