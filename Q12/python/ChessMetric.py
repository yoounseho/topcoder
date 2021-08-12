class ChessMetric:
    def __init__(self):
        self.ways = [[[0 for n in range(0, 55)] for m in range(0, 100)] for b in range(0, 100)]
        self.dx = [1, 1, 1, 0, -1, -1, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2]
        self.dy = [1, 0, -1, -1, -1, 0, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1]

    def howMany(self, size : int, start : list, end : list , numMoves : int):
        x : int = 0
        y : int= 0
        i : int= 0
        j : int= 0
        sx : int = start[0]
        sy : int = start[1]
        ex : int = end[0]
        ey : int = end[1]
        self.ways[sy][sx][0] = 1

        for i in range(1,numMoves+1) :
            for x in range(0,size):
                for y in range(0,size):
                    for j in range(0,16):
                        nx = x + self.dx[j]
                        ny = y + self.dy[j]

                        if nx< 0 or ny<0 or nx>=size or ny >=size:
                            continue

                        self.ways[ny][nx][i] += self.ways[y][x][i-1]
        return self.ways[ey][ex][numMoves]

print(ChessMetric().howMany(3,[0,0],[1,0],1))
print(ChessMetric().howMany(3,[0,0],[1,2],1))
print(ChessMetric().howMany(3,[0,0],[2,2],1))
print(ChessMetric().howMany(3,[0,0],[0,0],2))
print(ChessMetric().howMany(100,[0,0],[0,99],50))