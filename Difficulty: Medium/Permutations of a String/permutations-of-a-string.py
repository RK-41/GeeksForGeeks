#User function Template for python3

class Solution:
    def findPermutation(self, s):
        # Code here
        # 28.01.25 potd
        ans = set()
        ele = [i for i in s]
        self.fun(ans, 0, ele)
        
        return list(ans)
        
    def fun(self, ans, idx, ele):
        if len(ele) == idx:
            ans.add(''.join(ele))
            return 
        
        for i in range(idx, len(ele)):
            ele[i], ele[idx] = ele[idx], ele[i]
            self.fun(ans, idx+1, ele)
            ele[i], ele[idx] = ele[idx], ele[i]



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.findPermutation(S)
        ans.sort()
        for i in ans:
            print(i, end=" ")
        print()
        print("~")

# } Driver Code Ends