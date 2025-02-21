
class Solution:
    def isBalanced(self, s):
        # code here
        # 21.02.25 POTD
        
        def pair(b):
            match b:
                case '(':   return ')'
                case '{':   return '}'
                case '[':   return ']'
                
        stk = []
        
        for b in s:
            if b in [')', '}', ']']:
                if not stk or stk[-1] != b:
                    return False
                
                stk.pop()
                
            else:
                stk.append(pair(b))
                
        return len(stk) == 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

#Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = str(input())
        obj = Solution()
        if obj.isBalanced(s):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends