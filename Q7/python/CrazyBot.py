class CrazyBot:
    def __init__(self):
        self.grid = [ [False for n in range(0,100)] for m in range(0,100)] # 2차원 배열선언
        #동 서 남 북 순으로 움직임.
        self.vx = [1,-1,0,0]
        self.vy = [0,0,-1,1]
        self.prob = [ 0 for _ in range(0,4)]
        pass

    def getProbability(self, n : int, east :int, west: int, south : int, north : int):
        self.prob[0] = east/100.0
        self.prob[1] = west / 100.0
        self.prob[2] = south / 100.0
        self.prob[3] = north / 100.0

        return self.dfs(50,50, n)

    def dfs(self, x : int, y: int, n: int):
        if self.grid[x][y] == True :
            return 0
        if n == 0 :
            return 1

        self.grid[x][y] = True
        ret = 0.0
        for i in range(0,4):
             ret += self.dfs(x + self.vx[i] , y + self.vy[i] , n -1) * self.prob[i]

        #초기상태로 돌려놓아서 다음 검색을 할수 있게 해줌.
        self.grid[x][y] = False

        return ret

print(CrazyBot().getProbability(1,25,25,25,25))
print(CrazyBot().getProbability(2,25,25,25,25))
print(CrazyBot().getProbability(7,50,0,0,50))
print(CrazyBot().getProbability(14,50,50,0,0))
print(CrazyBot().getProbability(14,25,25,25,25))