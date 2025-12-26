#User function Template for python3
class Solution:
    def kthMissing(self, arr, k):
        # code here
        # 24.12.24
        # 26.12.25 (potd)
        lo, hi = 0, len(arr)-1
        
        while lo <= hi:
            mid = (lo + hi)//2
            missingCount = arr[mid] - (mid + 1)
            
            if missingCount < k:
                lo = mid + 1
            else:
                hi = mid - 1
                
        return k + hi + 1


