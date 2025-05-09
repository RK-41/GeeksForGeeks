#User function Template for python3

class Solution:
    
    #Function to find the largest number after k swaps.
    def findMaximumNum(self, s, k):
        #code here
        # 09.05.25 potd
        self.mx = s
        
        def solve(slist, k, idx):
            if k == 0 or idx == len(slist):
                    return
            
            mxChar = max(slist[idx:])
            if mxChar != slist[idx]:
                for i in range(len(slist) - 1, idx - 1, -1):
                    if slist[i] == mxChar:
                        if i != idx:
                            slist[idx], slist[i] = slist[i], slist[idx]
                            candidate = ''.join(slist)
                            
                            if candidate > self.mx:
                                self.mx = candidate
                            
                            solve(slist, k-1, idx+1)
                            
                            # Backtrack
                            slist[idx], slist[i] = slist[i], slist[idx]
                
            else:
                solve(slist, k, idx + 1)
        
        solve(list(s), k, 0)
        
        return self.mx



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        k = int(input())
        s = input()
        ob = Solution()
        print(ob.findMaximumNum(s, k))

        print("~")

# } Driver Code Ends