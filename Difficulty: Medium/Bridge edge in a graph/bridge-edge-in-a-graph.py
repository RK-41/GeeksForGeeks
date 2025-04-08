class Solution:
    def isBridge(self, V, edges, c, d):
        # code here 
        # 08.04.25 potd
        adj = [[] for _ in range(V)]
        vis = [False] * V
        
        # Adjacency list
        for u,v in edges:
            # Not storing the adjacency relationship between c and d
            if (u==c and v==d) or(u==d and v==c):
                continue
            
            adj[u].append(v)
            adj[v].append(u)
            
       
        # DFS traversal method
        def dfs(st):
            vis[st] = True
            
            for nb in adj[st]:
                if not vis[nb]:
                    dfs(nb)
        
        # Starting dfs traversal with c            
        dfs(c)
        
        # Returning answer by checking if d is visited or not
        return not vis[d]


#{ 
 # Driver Code Starts
import sys

sys.setrecursionlimit(10**7)
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        V = int(input())
        E = int(input())
        adj = [[] for _ in range(V)]
        edges = []

        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
            edges.append([u, v])

        c = int(input())
        d = int(input())

        obj = Solution()
        l = obj.isBridge(V, edges, c, d)

        if l:
            print("true")
        else:
            print("false")

        print("~")

# } Driver Code Ends