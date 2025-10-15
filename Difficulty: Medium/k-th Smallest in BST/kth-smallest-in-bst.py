#User function Template for python3

'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''

class Solution:
    # Return the kth smallest element in the given BST 
    def kthSmallest(self, root, k): 
        # 15.10.25 (potd)
        
        # Function to traverse the tree and find the kth
        #   smallest number
        def inOrder(node):
            # Declaring non-local variables
            nonlocal count, ans
            
            # Base case
            if not node or count >= k:
                return
            
            inOrder(node.left)
            
            count += 1
            
            # Setting the answer
            if count == k:
                ans = node.data
                return
            
            inOrder(node.right)
            
        # Initializing Variables
        ans, count = -1, 0
        
        # Calling the helper function
        inOrder(root)
        
        # Returning the answer
        return ans

