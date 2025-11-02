class Solution:
    def maxEdgesToAdd(self, V, edges):
        # code here
        # 02.11.25 potd
        return (V*(V-1))//2-len(edges)