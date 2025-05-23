#User function Template for python3


class Solution:
    
    #Function to rotate matrix anticlockwise by 90 degrees.
    def rotateby90(self, mat): 
        # code here
        # 21.12.24 POTD
        n = len(mat)
        i, j = 0, 0
        
        # Transpose
        for i in range(n):
            for j in range(i,n):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
                
        # Horizontal reverse
        for j in range(n):
            for i in range(n//2):
                mat[i][j], mat[n-1-i][j] = mat[n-1-i][j], mat[i][j]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1

    for _ in range(t):
        n = int(data[index])
        index += 1
        matrix = []
        for i in range(n):
            row = list(map(int, data[index:index + n]))
            matrix.append(row)
            index += n
        obj = Solution()
        obj.rotateby90(matrix)
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")
            print()

        print("~")

# } Driver Code Ends