class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, arr):
        #Your Code goes here.
        # 25.11.24 (POTD)
        majorityElements = []
        votesCount = {}
        n = len(arr)
        
        # Count votes for each candidates
        for candidate in arr:
            votesCount[candidate] = votesCount.get(candidate, 0) + 1
            
        # Find candidates with majority votes
        for candidate, votes in votesCount.items():
            if votes > n//3:
                majorityElements.append(candidate)
                
        majorityElements.sort()
                
        return majorityElements

