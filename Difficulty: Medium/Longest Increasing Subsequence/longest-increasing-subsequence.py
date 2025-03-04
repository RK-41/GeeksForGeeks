class Solution:
    def lis(self, arr):
        # code here
        # 04.03.25 potd
        
        def binSearch(seq, x):
            left, right = 0, len(seq)-1
            
            while left <= right:
                mid = (right - left)//2 + left
                
                if seq[mid] > x:
                    right = mid - 1
                elif seq[mid] < x:
                    left = mid + 1
                else:
                    return mid
                    
            return left
            
        seq = [arr[0]]
        
        for i in range(1, len(arr)):
            idx = binSearch(seq, arr[i])
            
            if idx == len(seq):
                seq.append(arr[i])
            else:
                seq[idx] = arr[i]
                
        return len(seq)
       



#{ 
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    for _ in range(int(input())):
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.lis(a))
        print("~")
# } Driver Code Ends