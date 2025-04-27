#User function Template for python3

class Solution:
    def multiplyStrings(self, a, b):
        # code here
        # return the product string
        # 27.04.25 (potd)
        n, m = len(a), len(b)
        s1, s2 = '', ''
        
        if a[0] == '-':
            s1 = '-'
            a = a[1:]
        
        if b[0] == '-':
            s2 = '-'
            b = b[1:]
            
        if s1 == '-' and s2 == '-':
            s1 = s2 = ''
            
        n, m = len(a), len(b)
        ans = [0] * (n + m)
        
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                p = int(a[i]) * int(b[j]) + (ans[i+j+1])
                ans[i+j+1] = p % 10
                ans[i+j] += p // 10

        i = 0
        while i < len(ans) and ans[i] == 0:
            i += 1
        
        if i == len(ans):
            return '0'
            
        return s1 + s2 + ''.join(str(c) for c in ans[i:])
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a = input()
        b = input()
        print(Solution().multiplyStrings(a.strip(), b.strip()))

        print("~")

# } Driver Code Ends