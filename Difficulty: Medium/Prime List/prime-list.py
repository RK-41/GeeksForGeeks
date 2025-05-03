"""
Definition for singly Link List Node
class Node:
    def __init__(self,x):
        self.val=x
        self.next=None

"""

class Solution:
    def primeList(self, head):
        # code here
        # 03.05.25 potd
        primes = self.isPrime(10000 + 10)
        hd = head
        
        while hd:
            a, b = hd.val, hd.val
            
            while a>1 and primes[a] == False:
                a -= 1
            
            while primes[b] == False:
                b += 1
            
            if primes[a] and hd.val - a <= b - hd.val:
                hd.val = a
            else:
                hd.val = b
            
            hd = hd.next
        
        return head
    
    def isPrime(self, n):
        primes = [True] * (n+1)
        primes[0] = primes[1] = False
        
        i = 2
        while i**2 <= n:
            if primes[i]:
                for j in range(i**2, n+1, i):
                    primes[j] = False
                
            i += 1
        
        return primes



#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.val = x
        self.next = None


def printList(node):
    while (node != None):
        print(node.val, end=" ")
        node = node.next
    print()


def inputList():

    val = [int(i) for i in input().strip().split()
           ]  #all data of linked list in a line
    head = Node(val[0])
    tail = head
    for i in range(1, len(val)):
        tail.next = Node(val[i])
        tail = tail.next
    return head


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        head = inputList()

        obj = Solution()
        res = obj.primeList(head)

        printList(res)

        print("~")

# } Driver Code Ends