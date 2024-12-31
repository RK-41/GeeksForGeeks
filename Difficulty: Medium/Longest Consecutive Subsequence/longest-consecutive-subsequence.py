 #User function Template for python3
 
class Solution:
    
    # arr[] : the input array
    
    #Function to return length of longest subsequence of consecutive integers.
    def longestConsecutive(self,arr):
        #code here
        # 31.12.24 POTD
        ans, mxLen, n = 1, 1, len(arr)
        arr.sort()
        
        for i in range(1, n):
            if arr[i-1] == arr[i]:
                continue
            elif arr[i-1] + 1 == arr[i]:
                mxLen += 1
            else:
                ans = max(ans, mxLen)
                mxLen = 1
                
        return max(ans, mxLen)


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
        print(Solution().longestConsecutive(a))
        print("~")
# } Driver Code Ends