class Solution:
     def sortIt(self, arr):
          # code here
          # 18.12.25 potd
          odd = []
          even = []
          for num in arr:
               if num % 2 == 0:
                    even.append(num)
               else:
                    odd.append(num)
          
          even.sort()
          odd.sort(reverse=True)
          arr[:] = odd + even