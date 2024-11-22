class Solution:
    def maximumProfit(self, prices):
        # code here
        # 22.11.24 POTD
        ans, n = 0, len(prices)
        mxLTR = [0]*n
        mx = prices[-1]
        
        # Find max element up to pos i from right to left
        for i in range(n-1,0,-1):
            if mx < prices[i]:
                mx = prices[i]
            mxLTR[i] = mx
            
        # Find diff b/w curr price and max price to it's right
        for i in range(n-1):
            ans = max(ans, mxLTR[i+1] - prices[i])
        
        return ans


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        # Read input and split it into a list of integers
        prices = list(map(int, input().split()))
        # Create a Solution object and calculate the result
        obj = Solution()
        result = obj.maximumProfit(prices)
        # Print the result
        print(result)

# } Driver Code Ends