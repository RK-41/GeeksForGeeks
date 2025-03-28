class Solution:
    def activitySelection(self, start, finish):
        #code here
        # 28.03.25 potd
        ans, arr, n, finishT = 0, [], len(start), -1
        
        for i in range(n):
            arr.append((finish[i], start[i]))
            
        arr.sort()
        
        for i in range(n):
            act = arr[i]
            
            if act[1] > finishT:
                ans += 1
                finishT = act[0]
                
        return ans

#{ 
 # Driver Code Starts
def main():
    t = int(input().strip())  # Number of test cases

    for _ in range(t):
        # Read the start times
        start = list(map(int, input().strip().split()))

        # Read the finish times
        finish = list(map(int, input().strip().split()))

        # Create solution object and call activitySelection
        obj = Solution()
        print(obj.activitySelection(start, finish))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends