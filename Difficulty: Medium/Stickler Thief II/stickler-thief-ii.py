class Solution:
    def maxValue(self, arr):
        # code here
        # 22.03.25 potd
        def rob(arr):
            chosen, notChosen = 0, 0
            
            for e in arr:
                nc = notChosen + e
                nnc = max(chosen, notChosen)
                chosen, notChosen = nc, nnc
                
            return max(chosen, notChosen)
        
        return max(rob(arr[:-1]), rob(arr[1:]))
        



#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self):
        arr = [int(i) for i in input().strip().split()]
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = IntArray().Input()

        obj = Solution()
        res = obj.maxValue(arr)

        print(res)
        print("~")

# } Driver Code Ends