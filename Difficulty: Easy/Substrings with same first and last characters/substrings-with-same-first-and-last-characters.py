class Solution:
	def countSubstring(self, s):
		# code here
		# 15.05.25 POTD
		ans = 0
		fr = {}
        
        for c in s:
            fr[c] = fr.get(c, 0) + 1
        
        for c in fr:
            ans += fr[c] + (fr[c] * (fr[c]-1)) // 2;
            
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.countSubstring(s)

        print(answer)
        print("~")

# } Driver Code Ends