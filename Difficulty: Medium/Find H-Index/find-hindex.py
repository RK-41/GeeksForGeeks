#User function Template for python3
class Solution:
    # Function to find hIndex
    def hIndex(self, citations):
        #code here
        # 18.08.25 (POTD)
        citations.sort(reverse=True)
        hIdx = 0
        
        for i, cit in enumerate(citations):
            if cit >= i+1:
                hIdx = i+1
            else:
                break
            
        return hIdx


