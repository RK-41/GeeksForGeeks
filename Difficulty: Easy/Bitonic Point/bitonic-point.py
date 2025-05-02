#User function Template for python3
class Solution:

	def findMaximum(self, arr):
		# code here
		# 02.05.25 POTD
		ans = 0
		
		for x in arr:
		    if x < ans: break
		    ans = x
		    
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaximum(arr)
        print(ans)
        tc -= 1
        print("~")

# } Driver Code Ends