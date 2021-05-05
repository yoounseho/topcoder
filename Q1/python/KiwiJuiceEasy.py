
class KiwiJuiceEasy:
    def __init__(self):
        pass

    def thePouring(self, cap, bottles, fromId, toId):
        for i in range(0,fromId.__len__()):
            f = fromId[i]
            t = toId[i]

            val = min(bottles[f], cap[t] - bottles[t])
            bottles[f] -= val
            bottles[t] += val

        return bottles

capacities = [14,35,86,58,25,62];
bottles = [6,34,27,38,9,60];
fromId = [1,2,4,5,3,3,1,0];
todoId = [0,1,2,4,2,5,3,1];

kiwiTest = KiwiJuiceEasy()
print(kiwiTest.thePouring(capacities,bottles,fromId,todoId))