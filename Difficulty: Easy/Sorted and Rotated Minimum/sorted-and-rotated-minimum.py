#User function Template for python3

class Solution:
    def findMin(self, arr):
        #complete the function here
        # 13.12.24 POTD
        if len(arr) == 1:
            return arr[0]
            
        for i in range(1, len(arr)):
            if arr[i-1] > arr[i]:
                return arr[i]
                
        return arr[0]


#{ 
 # Driver Code Starts
def main():
    T = int(input())

    while T > 0:
        a = list(map(
            int,
            input().strip().split()))  # Convert input to list of integers
        print(Solution().findMin(a))  # Call findMin with the array 'a'
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends