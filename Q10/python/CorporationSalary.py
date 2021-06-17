class CorporationSalary:
    def __init__(self):
        pass

    def totalSalary(self, relations : list):
        salary = [0 for i in range(0,relations.__len__())]
        i = 0
        while True:
            for i in range(0,relations.__len__()):
                #급여가 계산된 상태면 더이상 계산할 필요 없음.
                if salary[i] == 0:
                    bCheck : bool = False
                    for l in range(0,relations[i].__len__()):
                        if relations[i][l] == 'Y':
                            #아직 부하 급여가 계산이 안되었다면 계산할 필요 없음.
                            if salary[l] == 0:
                                bCheck = True

                    if bCheck is False:
                        sal : int = 0 # 급여 계산 시작
                        bFlag : bool = False
                        l = 0
                        for l in range(0,relations[i].__len__()):
                            if relations[i][l] == 'Y':
                                bFlag = True
                                sal = sal + salary[l]

                        if bFlag is False:
                            sal = 1
                        salary[i] = sal

            #탈출 조건 계산
            condition : int = 1
            for n in range(0,salary.__len__()):
                condition = condition * salary[n]

            if condition != 0:
                break

        sum : int = 0
        for m in range(0,salary.__len__()):
            sum = sum + salary[m]
        return sum

relations_1 = ["N"]
relations_2 = ["NNYN","NNYN","NNNN","NYYN"]
relations_3 = ["NNNNNN","YNYNNY","YNNNNY","NNNNNN","YNYNNN","YNNYNN"]
relations_4 = ["NYNNYN","NNNNNN","NNNNNN","NNYNNN","NNNNNN","NNNYYN"]
relations_5 = ["NNNN","NNNN","NNNN","NNNN"]

print(CorporationSalary().totalSalary(relations_1))
print(CorporationSalary().totalSalary(relations_2))
print(CorporationSalary().totalSalary(relations_3))
print(CorporationSalary().totalSalary(relations_4))
print(CorporationSalary().totalSalary(relations_5))