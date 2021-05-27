#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class MazeMaker
{
public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow,vector<int> moveCol)
    {
        int map[50][50] = {0};
        for(int i = 0; i<maze.size(); i++)
        {
            for(int j = 0;j<maze[0].size() ; j++)
            {
                map[i][j] = -1;
            }
        }

        map[startRow][startCol] = 0;
        queue<int> queue_x;
        queue<int> queue_y;
        queue_x.push(startCol);
        queue_y.push(startRow);
        while(queue_x.size() > 0)
        {
            int x = queue_x.front();
            int y = queue_y.front();
            queue_x.pop();
            queue_y.pop();

            for(int e = 0 ; e < moveRow.size() ; e++)
            {
                int nextX = x + moveCol[e];
                int nextY = y + moveRow[e];
                if((nextX >= 0 && nextX < maze[0].size()) && (nextY >= 0 && nextY < maze.size()))
                {
                    //maze 안에 다음좌표가 들어와야함
                    if(maze[nextY].substr(nextX,1) == ".")
                    {
                        //움직일수 있는공간이면
                        if(map[nextY][nextX] == -1)
                        {
                            map[nextY][nextX] = map[y][x] + 1;
                            queue_x.push(nextX);
                            queue_y.push(nextY);
                        }
                    }
                }
            }
        }

        cout<<"-------------------------------------------------------------------------------------"<<endl;
        for(int n = 0 ; n < maze.size() ; n++)
        {
            for(int m = 0; m < maze[0].size() ; m++)
            {
                cout<<maze[n].substr(m,1)<<"("<<map[n][m]<<")"<<"   ";
            }
            cout<<endl;
        }
        cout<<endl;

        int max = 0;
        for(int y = 0; y < maze.size(); y++)
        {
            for(int x = 0; x < maze[0].size(); x++)
            {
                //cout<<map[y][x] << " | "<<maze[y].substr(x,1)<<endl;
                if(map[y][x] == -1 && maze[y].substr(x,1) == ".")
                {
                    return -1;
                }
                max = std::max(max,map[y][x]);
            }
        }
       
        return max;
    }

  
};

int main()
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
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<MazeMaker().longestPath(maze_2,0,1,{1,0,-1,0,1,1,-1,-1},{0,1,0,-1,1,-1,1,-1})<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<MazeMaker().longestPath(maze_3,0,1,{1,0,-1,0},{0,1,0,-1})<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<MazeMaker().longestPath(maze_4,5,0,{1,0,-1,0,-2,1},{0,-1,0,1,3,0})<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<MazeMaker().longestPath(maze_5,0,0,{1,0,1,0,1,0},{0,1,0,1,0,1})<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<MazeMaker().longestPath(maze_6,0,0,{2,0,-2,0},{0,2,0,-2})<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;

    return 0;
}