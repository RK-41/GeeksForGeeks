#User function Template for python3


'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    #Function to return maximum path sum from any node in a tree.
    # 11.10.25 (POTD)
    def findMaxSum(self, root): 
        #Your code here
        # 14.02.25
        # Initializing a list with a negative infinity value
        ans = [-float("inf")]
        
        # Call the helper function to find the max path sum
        self.solve(root, ans)
        
        # Return the result/answer
        return ans[0]
        
    # Helper function to find max path sum
    def solve(self, node, ans):
        # Returning 0 for Null/None node
        if not node:    return 0
        
        # Getting non-negative sum of paths in left and 
        #   right subtrees
        leftSum = max(0, self.solve(node.left, ans))
        rightSum = max(0, self.solve(node.right, ans))
        
        # Updating answer with max of value
        ans[0] = max(ans[0], leftSum + rightSum + node.data)
        
        # Returning sum of current data and subtree's path's 
        #   sum with max value
        return node.data + max(leftSum, rightSum)
            

