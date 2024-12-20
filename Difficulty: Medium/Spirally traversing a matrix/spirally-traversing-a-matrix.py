class Solution:
    # Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self, mat):
        # code here
        # 20.12.24 POTD
        ans = []
        n, m = len(mat), len(mat[0])
        left, top, right, bottom = 0, 0, m-1, n-1

        while left<=right and top<=bottom:
            for j in range(left, right+1):
                ans.append(mat[top][j])
            top += 1
            
            for i in range(top, bottom+1):
                ans.append(mat[i][right])
            right -= 1
            
            if top<=bottom:
                for j in range(right, left-1, -1):
                    ans.append(mat[bottom][j])
                bottom -= 1
                
            if left<=right:
                for i in range(bottom, top-1, -1):
                    ans.append(mat[i][left])
                left += 1
                
        return ans


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1
    for _ in range(t):
        r = int(data[index])
        c = int(data[index + 1])
        index += 2
        matrix = []
        for i in range(r):
            row = list(map(int, data[index:index + c]))
            matrix.append(row)
            index += c

        solution = Solution()
        result = solution.spirallyTraverse(matrix)
        print(" ".join(map(str, result)))
        print("~")

# } Driver Code Ends