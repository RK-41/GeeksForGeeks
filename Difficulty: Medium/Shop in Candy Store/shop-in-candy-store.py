class Solution:
    # 12.08.25 potd
    def minMaxCandy(self, prices, k):
        minVal = 0
        prices.sort()
        low = 0
        high = len(prices)-1
        while low<=high:
            minVal+=prices[low]
            high-=k
            low+=1
        low =0
        high = len(prices)-1
        maxVal = 0
        while low<=high:
            maxVal+=prices[high]
            low+=k
            high-=1
        return [minVal,maxVal]