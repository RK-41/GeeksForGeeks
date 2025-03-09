#User function Template for python3

class Solution:

    def countPS(self, s):
        # code here
        
        ans = 0
        n = len(s)
        
        for i in range(n):
            # Checking for even length substring
            l, r = i-1, i
            while l>=0 and r<n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
                
            # Checking for odd length substring
            l, r = i-1, i+1
            while l>=0 and r<n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
        
        return ans
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.countPS(s))

        print("~")
# } Driver Code Ends