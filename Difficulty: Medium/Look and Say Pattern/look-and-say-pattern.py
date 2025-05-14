class Solution:
    def countAndSay(self, n):
        # code here
        # 14.05.25 POTD
        ans = [1]
        
        for i in range(n-1):
            x = []
            p = ans[0]
            c = 0
            for d in ans:
                if p == d:
                    c += 1
                else:
                    x.append(c)
                    x.append(p)
                    p = d
                    c = 1
            
            x.append(c)
            x.append(p)
            ans = x

        return ''.join(str(c) for c in ans)


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        n = int(input())

        solObj = Solution()

        print(solObj.countAndSay(n))

        print("~")
# } Driver Code Ends