#User function Template for python3
class Solution:
    # Function to find hIndex
    def hIndex(self, citations):
        #code here
        # 06.12.24 potd
        citations.sort(reverse=True)
        hIdx = 0
        
        for i, cit in enumerate(citations):
            if cit >= i+1:
                hIdx = i+1
            else:
                break
            
        return hIdx


#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends