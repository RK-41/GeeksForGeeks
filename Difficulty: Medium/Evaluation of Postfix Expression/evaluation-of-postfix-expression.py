#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends

class Solution:
    def evaluate(self, arr):
        # code here
        # 28.02.25 POTD
        stk = []
        
        for x in arr:
            if x in ['+', '-', '*', '/']:
                op2, op1 = stk.pop(), stk.pop()
                res = 0
                match x:
                    case '+':
                        res = op1 + op2
                    case '-':
                        res = op1 - op2
                    case '*':
                        res = op1 * op2
                    case '/':
                        res = op1 / op2
                
                stk.append(int(res))

            else:
                stk.append(int(x))
                
        return stk.pop()
        


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = input().split()
        solution = Solution()
        print(solution.evaluate(arr))
        print("~")

# } Driver Code Ends