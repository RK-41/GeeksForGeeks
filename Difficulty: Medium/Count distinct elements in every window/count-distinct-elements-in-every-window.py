class Solution:
    def countDistinct(self, arr, k):
        # 15.01.25 
        # 07.01.26 (potd)
        ans = []
        frequency = {}
        n = len(arr)

        # Storing frequency of elements in first window
        for i in range(k):
            frequency[arr[i]] = frequency.get(arr[i], 0) + 1
            
        # Storing count of distinct elements in first window
        ans.append(len(frequency))
        
        # Iterating array for rest subarray windows
        left, right = 0, k
        while right < n:
            # Decrementing count of element leaving the window
            frequency[arr[left]] -= 1
            
            # Incrementing count of  element entering the window
            frequency[arr[right]] = frequency.get(arr[right], 0) + 1

            # Removing element with 0 frequency
            if frequency[arr[left]] == 0:
                frequency.pop(arr[left])

            # Updating the answer and the pointers
            ans.append(len(frequency))
            left += 1
            right += 1
         
        # Returning the answer   
        return ans


