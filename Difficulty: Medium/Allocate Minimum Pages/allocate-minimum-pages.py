class Solution:
    
    #Function to find minimum number of pages
    def findPages(self, arr, k):
        # 18.12.24 potd
        if len(arr) < k:
            return -1
            
        l, h = max(arr), sum(arr)
        
        while l <= h:
            mid = (l+h)//2
            students = self.countStudents(arr, mid)
            
            if students > k:
                l = mid + 1
            else:
                h = mid - 1
                
        return l

    def countStudents(self, arr, pages):
        students = 1
        pagesStudent = 0
        n = len(arr)
        
        for i in range(n):
            if pagesStudent + arr[i] <= pages:
                pagesStudent += arr[i]
            else:
                students += 1
                pagesStudent = arr[i]
        
        return students
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.findPages(A, D)
        print(ans)
        print("~")

# } Driver Code Ends