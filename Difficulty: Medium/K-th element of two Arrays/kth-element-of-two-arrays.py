#User function Template for python3

class Solution:
    def kthElement(self, a, b, k):
        # 21.12.24
        # 29.12.25 (potd)
        m, n = len(a), len(b)
        i, j, ans = [0]*3
        
        # Travesing both arrays
        while i<m or j<n:
            k -= 1
            # If both arrays aren't exhausted
            if i<m and j<n:
                ans = min(a[i], b[j])
                if a[i] <= b[j]:
                    i += 1
                else:
                    j += 1
                    
            # If array 'b' is exhausted
            elif i<m:
                ans = a[i]
                i += 1
                
            # If array 'a' is exhausted
            else:
                ans = b[j]
                j += 1
            
            # Returning the kth element
            if k == 0:
                return ans



