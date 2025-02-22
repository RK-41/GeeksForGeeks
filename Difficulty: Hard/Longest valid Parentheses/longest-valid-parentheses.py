
class Solution:
    def maxLength(self, s):
        # code here
        # 22.02.25 POtd
        ans = 0
        stk = [-1]
        
        for i in range(len(s)):
            if s[i] == '(':
                stk.append(i)
            elif stk:
                stk.pop()
                if stk:
                    ans = max(ans, i - stk[-1])
                else:
                    stk.append(i)
                    
        return ans
        

#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.maxLength(S))
        print("~")

# } Driver Code Ends