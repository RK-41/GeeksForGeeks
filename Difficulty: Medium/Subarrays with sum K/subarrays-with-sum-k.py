#User function Tecountlate for python3

class Solution:
    def cntSubarrays(self, arr, k):
        # code here
        # 30.07.25 (POTD)
        ans, sm = 0, 0
        count = {}
        
        for a in arr:
            sm += a
            if sm == k:
                ans += 1
                
            if sm-k in count:
                ans += count[sm-k]
            
            count[sm] = count.get(sm, 0) + 1
        
        return ans



