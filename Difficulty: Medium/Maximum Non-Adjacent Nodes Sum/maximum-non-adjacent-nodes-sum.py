#User function Template for python3

'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque
class Solution:
    #Function to return the maximum sum of non-adjacent nodes.
    def getMaxSum(self, root):
        #code here
        # 13.10.25 (potd)
        def help(nd):
            if not nd:
                return [0, 0]
                
            left = help(nd.left)
            right = help(nd.right)
            include = nd.data + left[1] + right[1]
            exclude = max(left) + max(right)
            
            return [include, exclude]
        
        res = help(root)
        
        return max(res)


