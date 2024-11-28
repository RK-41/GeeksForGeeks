#User function template for Python
class Solution:
    def myAtoi(self, s):
        # Code here
        # 28.11.24 pOTd
        s = s.lstrip()
        ans = 0
        sign = 1
        mxInt = 2**31 - 1
        mnInt = -2**31
        
        if s and s[0] in ['+', '-']:
            if s[0] == '-':
                sign = -1
            s = s[1:]
        
        for c in s:
            if c.isdigit():
                ans = ans*10 + int(c)
            else:
                break;
                
        ans *= sign
        
        if ans > mxInt:
            return mxInt
        elif ans < mnInt:
            return mnInt
        else:
            return ans


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        ob = Solution()
        print(ob.myAtoi(s))
        print("~")

# } Driver Code Ends