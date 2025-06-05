from collections import defaultdict
from functools import cache
class Solution:
    def countPaths(self, edges, V, src, dest):
        #Code here
        # 05.06.25 potd
        graph = defaultdict(list)
        
        for u, v in edges:
            graph[u].append(v)
        
        @cache
        def dfs(node):
            if node==dest:
                return 1
            
            ans = 0
            for nx in graph[node]:
                ans += dfs(nx)
            
            return ans
        
        return dfs(src)