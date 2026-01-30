class Solution:
    def rearrangeQueue(self, q):
        #code here 
        # 30.01.26 potd
        r = deque()
        half = len(q) // 2
        for _ in range(half):
            r.append(q.popleft())
        
        for _ in range(half):
            q.append(r.popleft())
            q.append(q.popleft())