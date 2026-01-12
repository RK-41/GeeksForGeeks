class Solution:
    def maxOfSubarrays(self, arr, k):
        # 12.01.26 (potd)
        ans, dq = [], []
        n = len(arr)
        
        # Finding max element of first subarray of size k
        for i in range(k):
            while dq and dq[-1] < arr[i]:
                dq.pop()
                
            dq.append(arr[i])
            
        ans.append(dq[0])
        
        # Finding max elements of rest of the subarrays of length k
        for i in range(k, n):
            # Poping element from deque belonging to previous subarray
            if dq[0] == arr[i-k]:
                dq.pop(0)
                
            # Popping elements smaller than current element from deque
            while dq and dq[-1] < arr[i]:
                dq.pop()
                
            # Inserting current element into the deque
            dq.append(arr[i])
            
            # Updating answer
            ans.append(dq[0])
            
        # Returning a list of max elements from subarrays of length k
        return ans
        
        


