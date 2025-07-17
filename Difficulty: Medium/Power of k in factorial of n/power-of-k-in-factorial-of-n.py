class Solution:
    # 17.07.25 potd
	def prime_factor(self,n):
        i=2
        ans={}
        while i*i<=n:
            while n%i==0:
                ans[i]=ans.get(i,0)+1
                n//=i
            i+=1
        if n>1:
            ans[n]=ans.get(n,0)+1
        return ans
    
    def count_power(self,n,x):
        ans=0
        while n:
            n=n//x
            ans+=n
        return ans
        
    def maxKPower(self, n, k):
        kPrimeFact=self.prime_factor(k)
        ans=float("inf")
        for p,a in kPrimeFact.items():
            count=self.count_power(n,p)
            ans=min(ans,count//a)
        return ans