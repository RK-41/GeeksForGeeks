#User function Template for python3

class Solution:
    
    #Function to find the smallest positive number missing from the array.
    def missingNumber(self,arr):
        #Your code here
        # 27.11.24 pOTD
        ans, n = 1, len(arr)
        arr.sort()
        
        for i in range(n):
            if i>0 and arr[i]==arr[i-1]:
                continue
            elif arr[i]<=0:
                continue
            elif arr[i]==ans:
                ans += 1
            else:
                return ans
                
        return max(arr[-1]+1, 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.missingNumber(arr))
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends