#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class MazeMaker
{
public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow,vector<int> moveCol)
    {
        int max = 0;
        int width = maze[0].size();
        int height = maze.size();
        int board[50][50];

        for(int i = 0;i<height;i++)
            for(int j = 0; j <width ; j++)        
                board[i][j] = -1;

        board[startRow][startCol] = 0;
        queue<int> queueX;
        queue<int> queueY;
        queueX.push(startCol);
        queueY.push(startRow);

        while(queueX.size() > 0)
        {
            int x = queueX.front();
            int y = queueY.front();

            queueX.pop();
            queueY.pop();

            for(int i =0;i<moveRow.size();i++)
            {
                int nextX = x + moveCol[i];
                int nextY =  y + moveRow[i];

                if( 0<=nextX && nextX<width 
                    && 0<=nextY && nextY<height
                    && board[nextY][nextX] == -1
                    && maze[nextY].substr(nextX,1) == ".")
                {
                    board[nextY][nextX] = board[y][x] + 1;
                    queueX.push(nextX);
                    queueY.push(nextY);
                }
            }
        }

        for(int i =0;i<height;i++)
        {
            for(int j = 0; j<width;j++)
            {
                if(maze[i].substr(j,1) == "." && board[i][j] == -1)
                    return -1;
                max = std::max(max,board[i][j]);
            }
        }

        return max;
    }   
};

int main ()
{
    vector<string> maze_1 = {"...",
                             "...",
                             "..."};

    vector<string> maze_2 = {"...",
                             "...",
                             "..."};

    vector<string> maze_3 = {"X.X",
                             "...",
                             "XXX",
                             "X.X"};

    vector<string> maze_4 = {".......",
                             "X.X.X..",
                             "XXX...X",
                             "....X..",
                             "X....X.",
                             "......."};

    vector<string> maze_5 = {"......."};

    vector<string> maze_6 = {"..X.X.X.X.X.X."};

    cout<<MazeMaker().longestPath(maze_1,0,1,{1,0,-1,0},{0,1,0,-1})<<endl;
    cout<<MazeMaker().longestPath(maze_2,0,1,{1,0,-1,0,1,1,-1,-1},{0,1,0,-1,1,-1,1,-1})<<endl;
    cout<<MazeMaker().longestPath(maze_3,0,1,{1,0,-1,0},{0,1,0,-1})<<endl;
    cout<<MazeMaker().longestPath(maze_4,5,0,{1,0,-1,0,-2,1},{0,-1,0,1,3,0})<<endl;
    cout<<MazeMaker().longestPath(maze_5,0,0,{1,0,1,0,1,0},{0,1,0,1,0,1})<<endl;
    cout<<MazeMaker().longestPath(maze_6,0,0,{2,0,-2,0},{0,2,0,-2})<<endl;

    return 0;
}