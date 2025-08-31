
class Solution:
    def maxWater(self, arr):
        # code here
        # 18.01.25 (POTD)
        ans, left, right = 0, 0, len(arr)-1

        # Looping through the array using two pointers
        while left < right:
            # Calculating amount of water (area = width * height)
            water = (right-left) * min(arr[left],arr[right])
            ans = max(ans, water)
            
            # Closing down from the end with shorter line
            if arr[left] < arr[right]:
                left += 1
            elif arr[left] > arr[right]:
                right -= 1
            else:
                # Going for next taller line if both of the current 
                #   lines are equal
                if arr[left+1] > arr[right-1]:
                    left += 1
                else:
                    right -= 1
        
        # Returning max amount of water contained            
        return ans


