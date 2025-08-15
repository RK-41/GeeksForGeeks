#User function Template for python3

class Solution:
    def insertInterval(self, intervals, newInt):
        # Code here
        # 15.08.25 (POTD)
        ans = []
        n, i = len(intervals), 0
        
        # Adding intervals occuring before new interval
        while i<n and intervals[i][1] < newInt[0]:
            ans.append(intervals[i])
            i += 1
            
        # Merging intervals overlapping with new interval
        while i<n and newInt[1] >= intervals[i][0]:
            newInt[0] = min(newInt[0], intervals[i][0])
            newInt[1] = max(newInt[1], intervals[i][1])
            i += 1
        
        ans.append(newInt)
        
        # Adding intervals occuring after new interval
        while i<n:
            ans.append(intervals[i])
            i += 1
            
        # Returning final list with inserted new interval
        return ans
            

