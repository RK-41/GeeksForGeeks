import heapq
class Solution:
    def kClosest(self, points, k):
        # code here
        # 23.10.25 (potd)
        
        # Dictionary to store distance against the indices in points list
        distance = {}
        
        # Mapping the index to distance
        for i in range(len(points)):
            a, b = points[i][0], points[i][1]
            d = (a**2 + b**2)**0.5
            distance[i] = d
            
        # Extracting indices of k nearest points using heapq
        closest = heapq.nsmallest(k, distance, key=distance.get)
        
        # Returning a list of k nearest points
        return [points[i] for i in closest]
        