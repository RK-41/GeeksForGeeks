#User function Template for python3
class Solution:

	def nthRowOfPascalTriangle(self, n):
	    # code here
	    # 01.05.25 POTD
	    if n == 1:  return [1]
	    if n == 2:  return [1,1]
	    
	    ans = [1,1]
	    
	    for i in range(2,n):
	        up = [1]
	        
	        for j in range(1,len(ans)):
	            up.append(ans[j-1]+ans[j])
            
            up.append(1)
            ans = up

        return ans
            

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.nthRowOfPascalTriangle(n)
        for x in ans:
            print(x, end=" ")
        print()
        tc = tc - 1
        print("~")
# } Driver Code Ends