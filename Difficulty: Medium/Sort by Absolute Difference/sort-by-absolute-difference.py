class Solution:
    def rearrange(self, arr, x):
        # 17.08.25 potd
        arr.sort(key = lambda num : abs(num-x))
        return arr