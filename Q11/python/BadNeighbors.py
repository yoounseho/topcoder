class BadNeighbors:
    def __init__(self):
        pass

    def maxDonations(self, donations : list):
        max_1 = self.GetSum(donations,0)
        max_2 = self.GetSum(donations,1)
        return max(max_1,max_2)

    def GetSum(self, donations : list, startIndex : int):
        sum : list = [0 for i in range(0,donations.__len__())]

        bLastFlag : bool = False
        correction : int = 0
        if startIndex == 0 :
            bLastFlag = True
            correction = -1
        elif startIndex == 1:
            bLastFlag = False
            correction = 0
        i =0
        for i in range(startIndex,donations.__len__() + correction):
            if i-1 >= 0:
                if donations[i] + sum[i-2] > sum[i-1]:
                    sum[i] = donations[i] + sum[i-2]
                else:
                    sum[i] = sum[i-1]
            elif i-1 >= 0:
                if sum[i-1] < donations[i]:
                    sum[i] = donations[i]
                else:
                    sum[i] = sum[i-1]
            else:
                #첫번째 인덱스
                sum[i] =donations[i]

        maxsum : int  = 0
        for l in range(0,sum.__len__()):
            maxsum = max(maxsum,sum[l])
        return maxsum

donations_1 = [10, 3, 2, 5, 7, 8]
donations_2 = [11, 15]
donations_3 = [7, 7, 7, 7, 7, 7, 7]
donations_4 = [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]
donations_5 = [94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35,
                              47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72]#2926

print(BadNeighbors().maxDonations(donations_1))
print(BadNeighbors().maxDonations(donations_2))
print(BadNeighbors().maxDonations(donations_3))
print(BadNeighbors().maxDonations(donations_4))
print(BadNeighbors().maxDonations(donations_5))