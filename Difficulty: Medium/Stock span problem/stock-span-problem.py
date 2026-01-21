class Solution:
    def calculateSpan(self, arr):
        # 01.03.25 
        # 21.01.26 (potd)
        ans, stk, n = [], [], len(arr)

        for i in range(n):
            # Popping indices of elements that're smaller/equal
            #   to current element
            while stk and arr[i] >= arr[stk[-1]]:
                stk.pop()
                
            # Adding the span of current stock price
            ans.append((i - stk[-1]) if stk else (i + 1))
                
            # Inserting the current index in the stack
            stk.append(i)
            
        # Returning the answer
        return ans
        

