from collections import deque
class Solution:
    def longestSubarray(self, arr, x):
        # 08.0.25 (potd)
        minq, maxq, = deque(), deque()
        currMaxLen = ansSt = ansEnd = 0
        start = end = 0
        
        for i in range(len(arr)):
            end = i
            
            # Updating maxq deque
            while maxq and arr[maxq[-1]] < arr[i]:  maxq.pop()
            maxq.append(i)
            
            # Updating minq deque
            while minq and arr[minq[-1]] > arr[i]:  minq.pop()
            minq.append(i)
            
            # Popping indices of min and max elements from deques 
            #   having difference greater than x
            while arr[maxq[0]] - arr[minq[0]] > x:
                start += 1
                while minq and minq[0] < start: minq.popleft()
                while maxq and maxq[0] < start: maxq.popleft()
                    
            # Updating current max subarray length and ans indices
            if end - start + 1 > currMaxLen:
                currMaxLen = end - start + 1
                ansStart, ansEnd = start, end
        
        # Returning max length subarray with max difference of x
        return arr[ansStart : ansEnd + 1]

