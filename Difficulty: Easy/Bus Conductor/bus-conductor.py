class Solution:
    def findMoves(self, chairs, passengers):
        # 19.09.25 potd
        chairs.sort()
        passengers.sort()
        counter=0
        for i in range(len(chairs)):
            while chairs[i] < passengers[i]:
                chairs[i]+=1
                counter+=1
            while chairs[i] > passengers[i]:
                chairs[i]-=1
                counter+=1
        return counter

