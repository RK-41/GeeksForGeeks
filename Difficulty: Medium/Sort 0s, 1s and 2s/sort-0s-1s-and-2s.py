class Solution:
    # Function to sort an array of 0s, 1s, and 2s
    def sort012(self, arr):
        # code here
        # 10.12.24 
        # 02.01.26 (potd)
        # 04.01.26 (potd)
        lo, mid, hi = 0, 0, len(arr)-1
        
        while mid <= hi:
            if arr[mid] == 0:
                arr[lo], arr[mid] = arr[mid], arr[lo]
                lo += 1
                mid += 1
            elif arr[mid] == 1:
                mid += 1
            else:
                arr[hi], arr[mid] = arr[mid], arr[hi]
                hi -= 1
        

