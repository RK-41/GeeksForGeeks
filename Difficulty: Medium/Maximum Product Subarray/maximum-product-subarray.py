#User function Template for python3
class Solution:

    # Function to find maximum
    # product subarray
    def maxProduct(self,arr):
        # code here
        # 08.02.26 (potd)
        ans, leftProd, rightProd, n = arr[0], 1, 1, len(arr)
        # 'leftProd' for calculating product from left to right
        # 'rightProd' for claculating product from right ot left
        
        for i in range(n):
            # Update leftProd and rightProd if they're 0
            if leftProd == 0:
                leftProd = 1
            if rightProd == 0:
                rightProd = 1
                
            # Multiply respective elements to 'leftProd' and 'rightProd'
            # from left and right end respectively
            leftProd *= arr[i]
            rightProd *= arr[n-1-i]
            
            # Assign max product to 'ans'
            ans = max(ans, max(leftProd, rightProd))
            
        return ans


