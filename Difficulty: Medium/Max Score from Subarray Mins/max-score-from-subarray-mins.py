class Solution:
    def maxSum(self, arr):
        # code here
        # 05.07.25 potd
        max_sum = float('-inf')
        
        for i in range(1, len(arr)):
            pair_sum = arr[i - 1] + arr[i]
            if pair_sum > max_sum:
                max_sum = pair_sum
                
        return max_sum
    
