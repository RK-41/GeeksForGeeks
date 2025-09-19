class Solution:
    def minParentheses(self, s):
        # 19.09.25 potd
        stack=[]
        ans=0
        for e in s:
            if e=="(":
                stack.append(e)
            else:
                if stack:
                    stack.pop()
                else:
                    ans+=1
        ans+=len(stack)
        return ans