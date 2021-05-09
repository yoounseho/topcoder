class InterestingParty:
    def __init__(self):
        pass

    def bestInvitation(self, first, second):
        firstdict = dict()
        seconddict = dict()
        for i in first:
            firstdict[i] = 0
        for i in second:
            seconddict[i] = 0

        for i in first:
            firstdict[i] = firstdict[i]+1
        for i in second:
            seconddict[i] = seconddict[i]+1

        maxvalue= 0
        for i in firstdict:
            maxvalue = max(firstdict[i],maxvalue)
        for i in seconddict:
            maxvalue = max(seconddict[i],maxvalue)

        return maxvalue

first = ["snakes","programming","cobra","monty"]
second = ["python","python","anaconda","python"]

print(InterestingParty().bestInvitation(first,second))