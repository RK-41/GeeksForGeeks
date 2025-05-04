#User function Template for python3

class Solution:
    def findSubString(self, s):
        # code here
        # 04.5.25 POTD
        ans = n = len(s)
        l, r = 0, 0
        fr = {}
        u = len(set(c for c in s))

        while r < n:
            fr[s[r]] = fr.get(s[r], 0) + 1
            
            while len(fr) >= u:
                ans = min(ans, r - l + 1)

                fr[s[l]] -= 1
                if fr[s[l]] == 0:
                    fr.pop(s[l])
                
                l += 1
            
            r += 1

        return ans
    
    
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    T = int(input())
    while (T > 0):
        str = input()
        ob = Solution()
        print(ob.findSubString(str))

        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends