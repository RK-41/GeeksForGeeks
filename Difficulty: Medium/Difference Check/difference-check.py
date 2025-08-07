class Solution:
    def minDifference(self, arr):
        # 07.08.25 potd
        seconds = []
        for time in arr:
            timeUnits = time.split(':')
            s = 3600*int(timeUnits[0]) + 60*int(timeUnits[1]) + int(timeUnits[2])
            seconds.append(s)
        seconds.sort()
        seconds.append(seconds[0]+24*3600)
        n = len(seconds)
        ans = 2*24*3600
        for i in range(n-1):
            ans = min(ans, seconds[i+1]-seconds[i])
        
        return ans