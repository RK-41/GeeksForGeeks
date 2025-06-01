class Solution:
	def countPairs(self, mat1, mat2, x):
	    # 01.06.25 POTD
	    ans = 0
	    arr, brr = [], []
	    
	    for r in mat1:
	        for a in r:
	            arr.append(a)
	            
	    for r in mat2:
	        for a in r:
	            brr.append(a)

        t = len(arr)
        i, j = 0, len(arr)-1
        
        while i<t and j>=0:
            sm = arr[i] + brr[j]
            if sm == x:
                ans += 1
                i += 1
                j -= 1
            elif sm > x:
                j -= 1
            else:
                i += 1
        
        return ans