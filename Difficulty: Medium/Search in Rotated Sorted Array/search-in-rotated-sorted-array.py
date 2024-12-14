#User function Template for python3

class Solution:
    def search(self,arr,key):
        # Complete this function
        # 14.12.24 potd
        left, right = 0, len(arr)-1
        
        while left <= right:
            mid = (left+right)//2
            
            if arr[mid] == key:
                return mid
                
            if arr[left] <= arr[mid]:   # left half is sorted
                if key >= arr[left] and key < arr[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:   # right half is sorted
                if key > arr[mid] and key <= arr[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.search(A, k))
        print("~")

# } Driver Code Ends