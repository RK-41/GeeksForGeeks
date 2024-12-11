class Solution:
    def mergeArrays(self, a, b):
        # code here
        # 11.12.24 potd
        ai = len(a)-1
        bi = 0
        
        while ai>=0 and bi<len(b):
            if a[ai] > b[bi]:
                a[ai], b[bi] = b[bi], a[ai]
                ai -= 1
                bi += 1
            else:
                break
            
        a.sort()
        b.sort()


#{ 
 # Driver Code Starts
# Input handling and main function
if __name__ == "__main__":
    # Number of test cases
    t = int(input().strip())

    for _ in range(t):
        # Input first array
        a = list(map(int, input().strip().split()))
        # Input second array
        b = list(map(int, input().strip().split()))

        # Create solution object and merge the arrays
        solution = Solution()
        solution.mergeArrays(a, b)

        # Output both arrays in the same line space-separated
        print(" ".join(map(str, a)))
        print(" ".join(map(str, b)))

# } Driver Code Ends