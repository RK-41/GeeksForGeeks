
class Solution:
    def maxOfMins(self, arr):
        # code here
        # 26.02.25 potd
        n = len(arr)
        nxs = self.next_smaller(arr)
        pvs = self.previous_smaller(arr)
        res = [float('-inf')]*n
       
        for i in range(n):
            idx = nxs[i] - pvs[i] - 2
            res[idx] = max(res[idx], arr[i])
           
        stk = []
        
        for i in reversed(range(n)):
            while stk and res[stk[-1]] < res[i]:
                stk.pop()
                
            if stk: res[i] = max(res[i], res[stk[-1]])
            stk.append(i)
            
        return res
        
    def next_smaller(self, arr):
        n = len(arr)
        nxs = [n] * n
        stk = []
        
        for i in reversed(range(n)):
            while stk and arr[stk[-1]] >= arr[i]:
                stk.pop();
                
            if stk: nxs[i] = stk[-1]
            stk.append(i)
            
        return nxs
        
    def previous_smaller(self, arr):
        n = len(arr)
        pvs = [-1]*n
        stk = []
        
        for i in range(n):
            while stk and arr[stk[-1]] >= arr[i]:
                stk.pop()
                
            if stk: pvs[i] = stk[-1]
            stk.append(i)
            
        return pvs


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        solution = Solution()
        result = solution.maxOfMins(arr)
        print(" ".join(map(str, result)))
        print("~")
# } Driver Code Ends