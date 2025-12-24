class Solution:
     def countLessEqual(self, arr, x):
          # code here
          # 24.12.25 potd
          arr.sort()
          n = len(arr)
          count = 0

          for i in range(n):
               if arr[i] > x:
                    break
               count += 1

          return count