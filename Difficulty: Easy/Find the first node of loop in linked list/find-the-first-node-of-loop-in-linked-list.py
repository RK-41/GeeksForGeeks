#User function Template for python3

""" Node Class
    class Node:
        def __init__(self, data):   # data -> value stored in node
            self.data = data
            self.next = None
"""
class Solution:
    def findFirstNode(self, head):
        #code here
        # 25.01.25 POtd
        if not head:    return None
        
        fast, slow = head, head
        
        while fast and fast.next:
            if fast.next:
                fast = fast.next.next
            slow = slow.next
            
            if fast == slow:
                break
            
        if fast != slow:    return None
        
        slow = head
        while fast != slow:
            fast = fast.next
            slow = slow.next
        
        return fast

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def print_list(node):
    while node:
        print(node.data, end=' ')
        node = node.next
    print()


def loop_here(head, tail, position):
    if position == 0:
        return

    walk = head
    for _ in range(1, position):
        walk = walk.next
    tail.next = walk


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        k = int(input())
        head = Node(arr[0])
        tail = head
        for value in arr[1:]:
            tail.next = Node(value)
            tail = tail.next
        loop_here(head, tail, k)

        ob = Solution()
        ans = ob.findFirstNode(head)
        if (ans == None):
            print(-1)
        else:
            print(ans.data)
        print("~")

# } Driver Code Ends