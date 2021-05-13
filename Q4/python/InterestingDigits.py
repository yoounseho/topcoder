import pdb

class InterestingDigits:
    def __init__(self):
        pass

    def digits(self, base):
        returnvalue = []
        for n in range(2,base):
            successful = True
            i = 1

            while n*i < 1000:
                v = n*i
                converted = []

                while v > base:
                    converted.append(v%base)
                    v = int(v/ base) # 몇개로 나눠지느냐만 봐야하기때문에 int형으로 변환해야함
                converted.append(v)

                sum = 0
                for num in converted:
                    sum += num

                if float(int(sum/n)) != float(sum/n):
                    successful = False
                    break

                i = i+1

            if successful:
                returnvalue.append(n)

        return returnvalue

a = input()
print(InterestingDigits().digits(int(a)))