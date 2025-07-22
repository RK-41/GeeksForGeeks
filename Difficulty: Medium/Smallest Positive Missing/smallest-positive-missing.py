#User function Template for python3

class Solution:
    
    #Function to find the smallest positive number missing from the array.
    def missingNumber(self,arr):
        #Your code here
        # 22.07.25 (POTD)
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


