#User function Template for python3
class Solution:
    # Function to return Breadth First Search Traversal of given graph.
    def bfs(self, adj):
        # code here
        # 02.04.25 POTD
        n = len(adj)
        ans, q, vis = [], [], [0] * n
        
        q.append(0)
        
        while q:
            node = q[0]
            q.pop(0)
            
            if vis[node] == 0:
                ans.append(node)
                vis[node] = 1
            
            for nd in adj[node]:
                if vis[nd] == 0:
                    q.append(nd)

        return ans

#{ 
 # Driver Code Starts
import sys


#Position this line where user code will be pasted.
def main():
    tc = int(sys.stdin.readline().strip())

    for _ in range(tc):
        V = int(sys.stdin.readline().strip())  # Number of vertices
        adj = []  # Adjacency list

        for _ in range(V):
            input_line = sys.stdin.readline().strip()
            node = list(map(int, input_line.split())) if input_line else []
            adj.append(node)

        obj = Solution()
        ans = obj.bfs(adj)
        print(" ".join(map(str, ans)))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends