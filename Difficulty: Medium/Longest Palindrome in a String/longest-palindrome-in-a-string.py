
class Solution:
    def longestPalindrome(self, s):
        # code here
        # 08.03.25 potd
        ans = ''
        ansLen = 0
        
        for i in range(len(s)):
            # Odd len
            l, r = i, i
            
            while l>=0 and r<len(s) and s[l] == s[r]:
                if (r-l+1) > ansLen:
                    ans = s[l: r+1]
                    ansLen = r-l+1
                
                l -= 1
                r += 1
            
            # Even len
            l, r = i, i+1
            
            while l>=0 and r<len(s) and s[l] == s[r]:
                if (r-l+1) > ansLen:
                    ans = s[l: r+1]
                    ansLen = r-l+1
                    
                l -= 1
                r += 1
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalindrome(S)

        print(ans)
        print("~")
# } Driver Code Ends