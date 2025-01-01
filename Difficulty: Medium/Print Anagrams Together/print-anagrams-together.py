#User function Template for python3


class Solution:

    def anagrams(self, arr):
        '''
        words: list of word
        n:      no of words
        return : list of group of anagram {list will be sorted in driver code (not word in grp)}
        '''

        #code here
        # 01.01.24 POTD
        ans = []
        gr = {}
        
        for s in arr:
            # Converting s into sorted key
            ss = list(s)
            ss.sort()
            key = ''.join(ss)
            
            # Adding s to gr[key]
            lst = gr.get(key, [])
            lst.append(s)

            # Updading gr[key]
            gr[key] = lst
                
        # Traversing groups dictionary
        for g in gr:
            ans.append(gr[g])
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        words = input().split()

        ob = Solution()
        ans = ob.anagrams(words)

        for grp in sorted(ans):
            for word in grp:
                print(word, end=' ')
            print()

        print("~")

# } Driver Code Ends