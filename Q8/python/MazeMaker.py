from queue import Queue
import pdb

class MazeMaker:
    def __init__(self):
        pass

    def longestPath(self, maze : list, startRow : int, startCol : int, moveRow : list, moveCol : list):
        map = [ [-1 for l in range(0,50)] for i in range(0,50)]

        map[startRow][startCol] = 0
        queue_x = Queue()
        queue_y = Queue()
        queue_x.put(startCol)
        queue_y.put(startRow)

        while queue_x.qsize() > 0:
            x = queue_x.get()
            y = queue_y.get()

            for e in range(0, moveRow.__len__() ):
                nextX = x + moveCol[e]
                nextY = y + moveRow[e]

                if (nextX >= 0 and nextX<maze[0].__len__()) and (nextY >= 0 and nextY < maze.__len__()):
                    if map[nextY][nextX] == -1 and maze[nextY][nextX] == '.':
                        map[nextY][nextX] = map[y][x] +1
                        queue_x.put(nextX)
                        queue_y.put(nextY)

        print("-------------------------------------")
        for n in range(0,10):
            for m in range(0,10):
                print(map[n][m] ,end="")
                if n < maze.__len__() and m < maze[0].__len__():
                    print("(" +maze[n][m]+ ")", end= " ")
                else:
                    print("",end = " ")
            print("")

        maxnum = 0
        for y in range(0,maze.__len__()):
            for x in range(0,maze[0].__len__()):
                if map[y][x] == -1 and maze[y][x] == '.':
                    return -1
                maxnum = max(maxnum, map[y][x])
        return maxnum

maze_1 = ["...",
          "...",
          "..."]

maze_2 = ["...",
          "...",
          "..."]

maze_3 = ["X.X",
          "...",
          "XXX",
          "X.X"]

maze_4 = [".......",
          "X.X.X..",
          "XXX...X",
          "....X..",
          "X....X.",
          "......."]

maze_5 = ["......."]

maze_6 = ["..X.X.X.X.X.X."]

print(MazeMaker().longestPath(maze_1, 0, 1, [1, 0, -1, 0], [0, 1, 0, -1]) )
print(MazeMaker().longestPath(maze_2, 0, 1, [1, 0, -1, 0, 1, 1, -1, -1], [0, 1, 0, -1, 1, -1, 1, -1]))
print(MazeMaker().longestPath(maze_3, 0, 1, [1, 0, -1, 0], [0, 1, 0, -1]))
print(MazeMaker().longestPath(maze_4, 5, 0, [1, 0, -1, 0, -2, 1], [0, -1, 0, 1, 3, 0]))
print(MazeMaker().longestPath(maze_5, 0, 0, [1, 0, 1, 0, 1, 0], [0, 1, 0, 1, 0, 1]))
print(MazeMaker().longestPath(maze_6, 0, 0, [2, 0, -2, 0], [0, 2, 0, -2]))