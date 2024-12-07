class Solution:
    #User function Template for python3
    #Function to count inversions in the array.
    def inversionCount(self, arr):
        # Your Code Here
        # 07.12.24 potd
        self.count = 0
        
        def mergeSort(arr, temp, left, right):
            if left < right:
                mid = (left+right)//2
                mergeSort(arr, temp, left, mid)
                mergeSort(arr, temp, mid+1, right)
                merge(arr, temp, left, mid, right)
        
        def merge(arr, temp, left, mid, right):
            # Staring indices of left & right subarray
            i, j = left, mid+1  
            # Starting index to be sorted
            k = left
            invCount = 0
            
            while i<=mid and j<=right:
                if arr[i] <= arr[j]:
                    temp[k] = arr[i]
                    i += 1
                else:
                    temp[k] = arr[j]
                    # All ele left in the left half are greater
                    invCount += (mid-i+1)
                    j += 1
                k += 1
                
            while i<=mid:
                temp[k] = arr[i]
                i += 1
                k += 1
                
            while j<=right:
                temp[k] = arr[j]
                j += 1
                k += 1
                
            for i in range(left, right+1):
                arr[i] = temp[i]
                
            self.count += invCount
            
        n = len(arr)
        temp = [0]*n
        mergeSort(arr, temp, 0, n-1)
        
        return self.count


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a))
        print("~")

# } Driver Code Ends