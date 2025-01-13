
class Solution:
    def maxWater(self, arr):
        # code here
        # 13.01.25 POTD
        ans, left, right = 0, 0, len(arr)-1

        while left < right:
            ans = max(ans, (right-left)*min(arr[left],arr[right]))
            
            if arr[left] < arr[right]:
                left += 1
            elif arr[left] > arr[right]:
                right -= 1
            else:
                if arr[left+1] > arr[right-1]:
                    left += 1
                else:
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