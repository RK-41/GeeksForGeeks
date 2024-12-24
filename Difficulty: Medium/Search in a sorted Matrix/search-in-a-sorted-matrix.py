
#User function Template for python3

class Solution:
    
    #Function to search a given number in row-column sorted matrix.
    def searchMatrix(self, mat, x): 
    	# code here 
    	# 24.12.24 POTD
    	n, m = len(mat), len(mat[0])
    	i, j = 0, m-1
    	
    	while i < n and j > -1:
    	    if x > mat[i][j]:
    	        i += 1
    	    elif x < mat[i][j]:
    	        j -= 1
    	    else:
    	        return True
                
        return False
    	



#{ 
 # Driver Code Starts
# Initial Template for Python 3

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
        x = int(data[index])
        index += 1
        ob = Solution()
        if ob.searchMatrix(matrix, x):
            print("true")
        else:
            print("false")
        print("~")
# } Driver Code Ends