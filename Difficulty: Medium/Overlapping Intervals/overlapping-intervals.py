class Solution:
	def mergeOverlap(self, arr):
		#Code here
		# 08.12.24 POTD
        ans = []
        arr.sort()
        s, e = arr[0][0], arr[0][1]
        
        for i in arr:
            if e >= i[0]:
                e = max(e, i[1])
            else:
                ans.append([s,e])
                s, e = i[0], i[1]
                
        ans.append([s,e])
            
        return ans


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        # a = list(map(int, input().strip().split()))
        arr = []
        # j = 0
        for i in range(n):
            a = list(map(int, input().strip().split()))
            x = a[0]
            # j += 1
            y = a[1]
            # j += 1
            arr.append([x, y])
        obj = Solution()
        ans = obj.mergeOverlap(arr)
        for i in ans:
            for j in i:
                print(j, end=" ")
        print()

# } Driver Code Ends