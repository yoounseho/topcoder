#import sys

class Crytography:
    def __init__(self):
        pass

    def encrypt(self, numbers : list):
        maximum = 0
        for i in range(0, numbers.__len__()):
            numbers[i] = numbers[i] + 1
            value = 1
            for num in numbers:
                value *= num
                #print(sys.getsizeof(value))
                pass
            maximum = max(maximum, value)
            numbers[i] = numbers[i] - 1
        #파이썬에서의 변수의 크기는 미리 크게잡아두고 필요에의해 크거나 작아지거나 할 수 있음.?
        return maximum

numbers = [1000,999,998,997,996,995]
print(Crytography().encrypt(numbers))