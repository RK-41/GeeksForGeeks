class Solution:
    #Function to check if two strings are rotations of each other or not.
    def areRotations(self,s1,s2):
        # 09.12.24 
        # 16.12.25 (potd)
        # APPROACH: Pattern Search using KMP-Algorithm
        text, pat = s1 + s1, s2
        n, i, lpsLen = len(s2), 1, 0
        lpsArr = [0]*n
        
        # Computing LPS Array
        while i<n:
            if pat[i] == pat[lpsLen]:
                lpsLen += 1
                lpsArr[i] = lpsLen
                i += 1
            else:
                if lpsLen != 0:
                    lpsLen = lpsArr[lpsLen-1]
                else:
                    lpsArr[i] = 0
                    i += 1
                    
        # Checking for presence of pattern in text
        i, j, m = 0, 0, len(text)
        while i<m:
            if text[i] == pat[j]:
                i += 1
                j += 1
                
            if j == n:
                return True
            elif i<m and text[i] != pat[j]:
                if j>0:
                    j = lpsArr[j-1]
                else:
                    i += 1
                
        return False
        


