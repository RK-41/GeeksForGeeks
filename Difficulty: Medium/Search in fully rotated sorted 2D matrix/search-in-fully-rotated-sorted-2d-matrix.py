class Solution:
    def searchMatrix(self, mat, x):
        # code here
        # 20.08.25 potd
        for lst in mat:
            if x in lst:
                return True
                
        return False