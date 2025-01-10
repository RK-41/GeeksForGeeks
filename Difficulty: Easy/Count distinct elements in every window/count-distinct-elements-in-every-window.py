
class Solution:
    def countDistinct(self, arr, k):
        # Code here
        # 10.01.25 POTD
        ans = []
        fr = {}
        n = len(arr)

        for i in range(k):
            fr[arr[i]] = fr.get(arr[i], 0) + 1
            
        ans.append(len(fr))
        
        for i in range(k,n):
            fr[arr[i-k]] -= 1
            fr[arr[i]] = fr.get(arr[i], 0) + 1

            if fr[arr[i-k]] == 0:
                fr.pop(arr[i-k])

            ans.append(len(fr))
            
        return ans


#{ 
 # Driver Code Starts
import sys
from collections import defaultdict
if __name__ == '__main__':
    input = sys.stdin.read
    data = input().splitlines()
    t = int(data[0])
    index = 1
    while t > 0:
        arr = list(map(int, data[index].strip().split()))
        index += 1
        k = int(data[index])
        index += 1

        ob = Solution()
        res = ob.countDistinct(arr, k)

        for element in res:
            print(element, end=" ")
        print()
        print("~")

        t -= 1

# } Driver Code Ends