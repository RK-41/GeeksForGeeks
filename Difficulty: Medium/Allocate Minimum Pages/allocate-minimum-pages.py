class Solution:
    #Function to find minimum number of pages
    def findPages(self, arr, k):
        # 23.12.24 (POTD)
        if len(arr) < k:
            return -1
            
        leastMaxPages, maxPages = max(arr), sum(arr)
        
        while leastMaxPages <= maxPages:
            currPages = (leastMaxPages + maxPages)//2
            students = self.countStudents(arr, currPages)
            
            if students > k:
                leastMaxPages = currPages + 1
            else:
                maxPages = currPages - 1
                
        return leastMaxPages

    #Function to count no. of students having at least 'pages' pages
    def countStudents(self, arr, pages):
        students = 1
        pagesForCurrStudent = 0
        n = len(arr)
        
        for i in range(n):
            if pagesForCurrStudent + arr[i] <= pages:
                pagesForCurrStudent += arr[i]
            else:
                students += 1
                pagesForCurrStudent = arr[i]
        
        return students
        


