#User function Template for python3


class Solution:
    
    #Function is to check whether two strings are anagram of each other or not.
    def areAnagrams(self, s1, s2):
        #code here
        # 30.11.24 POTd
        if len(s1) != len(s2):
            return False
            
        charDict = {}
        
        for c in s1:
            charDict[c] = charDict.get(c,0) + 1
            
        for c in s2:
            if c not in charDict or charDict[c] == 0:
                return False
                
            charDict[c] -= 1
            
        return True


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        a = input().strip()
        b = input().strip()
        if (Solution().areAnagrams(a, b)):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends