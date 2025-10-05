class Solution:
     def ratInMaze(self, maze):
        # code here
        # 05.10.25 potd
        ans = []
        n = len(maze)
        visited = set()
        dirs = {
            'U': (-1, 0),
            'D': (1, 0),
            'L': (0, -1),
            'R': (0, 1)
        }
        def dfs(path, r, c):
            nonlocal ans, visited, dirs
            if (r, c) == (n-1, n-1):
                ans.append(path)
                return
            visited.add((r, c))
    
            for dir, (dr, dc) in dirs.items():
                nr, nc = r+dr, c+dc
                if nr >= n or nr < 0 or nc >= n or nc < 0:
                    continue
                if (nr, nc) not in visited and maze[nr][nc] != 0:
                    dfs(path+dir, nr, nc)
            visited.remove((r, c))
        
        dfs("", 0, 0)
        return sorted(ans)