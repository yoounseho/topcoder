class FriendScore:
    def __init__(self):
        pass

    def highestScore(self, friends : list):
        friendlist = friends
        #mutable 이기 때문에 callbyreference가 되버림. 계산과정을 기록하는건 원치않으므로 리스트를 새로작성.
        friendnum =  [0] * friendlist.__len__()
        for i in range(0,friendlist.__len__()):
            commonFriends = list()
            for j in range(0,friendlist.__len__()):
                if friendlist[i][j] == 'Y':
                    commonFriends.append(j)

            for n in range(0,commonFriends.__len__()):
                for m in range(0,commonFriends.__len__()):
                    if n != m:
                        #str은 immutable 형태이기때문에 list형태로 변환뒤 조작후 다시 str형태로 변환
                        changeStr : str= friendlist[commonFriends[n]]
                        changeList = []
                        for c in range(0,changeStr.__len__()):
                            changeList.append(changeStr[c])
                        changeList[commonFriends[m]] = 'Y'

                        sumStr = ''.join(changeList)
                        friendlist[commonFriends[n]] = sumStr

        #위에서 사용했으므로 한번 초기화
        i = 0
        j = 0
        for i in range(0,friendlist.__len__()):
            for j in range(0,friendlist.__len__()):
                if friendlist[i][j] == 'Y':
                    friendnum[i]+= 1
                print(friendlist[i][j] + " ",end="")
            print("")

        friendnum.sort()
        return friendnum[-1]

friends_1 = [
                "NNN",
                "NNN",
                "NNN"
             ]

friends_2 = [
                "NYY",
                "YNY",
                "YYN"
             ]

friends_3 = [
                "NYNNN",
                "YNYNN",
                "NYNYN",
                "NNYNY",
                "NNNYN"
             ]

friends_4 = [
            "NNNNNNNNNNNNNNY",
            "NNNNNNNNNNNNNNN",
            "NNNNNNYNNNNNNNN",
            "NNNNNNYNNNNNNNY",
            "NNNNNNNNNNNNNNY",
            "NNNNNNNNYNNNNNN",
            "NNNNNNNNNNNNNNN",
            "NNYYNNNNNNNNNNN",
            "NNNNNYNNNNNYNNN",
            "NNNNNNNNNNNNNNY",
            "NNNNNNNNNNNNNNN",
            "NNNNNNNNYNNNNNN",
            "NNNNNNNNNNNNNNN",
            "NNNNNNNNNNNNNNN",
            "YNNYYNNNNYNNNNN"
         ]

print(FriendScore().highestScore(friends_1))
print(FriendScore().highestScore(friends_2))
print(FriendScore().highestScore(friends_3))
print(FriendScore().highestScore(friends_4))

