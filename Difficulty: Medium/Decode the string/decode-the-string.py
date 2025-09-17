class Solution:
    def decodedString(self, s):
        # 17.09.25 (POTD)
        stk, currentStr, nextK = [], "", 0
        
        for char in s:
            # Calculating k for next nested encoded substring
            if char.isdigit():
                nextK = nextK * 10 + int(char)
            
            # Pushing current string and next k into stack
            elif char == '[':
                stk.append((currentStr, nextK))
                currentStr, nextK = "", 0
            
            # Popping last string and current k from stack
            elif char == ']':
                lastStr, currentK = stk.pop()
                currentStr = lastStr + currentStr * currentK
                
            # Appending alphabet character to the string
            else:
                currentStr += char
                
        # Returning final decoded string
        return currentStr
            
        

