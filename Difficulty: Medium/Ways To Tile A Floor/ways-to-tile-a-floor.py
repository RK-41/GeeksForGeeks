class Solution:
    def numberOfWays(self, n):
        # 06.11.25 potd
        if n==1 or n==2:
            return n
        a,b=1,2
        for _ in range(n-2):
            b,a=a+b,b
        return b