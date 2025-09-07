#User function Template for python3
'''
class Node:
    def _init_(self,x):
        self.data = x
        self.next = None
'''
import heapq
class Solution:
    def mergeKLists(self, arr):
        # code here
        # 24.02.25 (POTD)
        ans = Node(0)
        data = []
        
        # Storing data of all the sorted lists in a min heap
        for slist in arr:
            while slist:
                heapq.heappush(data, slist.data)
                slist = slist.next
        
        # Creating the sorted linked list
        ref = ans
        while data:
            ref.next = Node(heapq.heappop(data))
            ref = ref.next
            
        # Returning the merged sorted linked list
        ans = ans.next
        return ans


