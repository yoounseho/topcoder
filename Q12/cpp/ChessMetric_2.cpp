#include <iostream>
#include <vector>

using namespace std;

long long ways[100][100][55] = {0};
int dx[] = { 1,1,1,0,-1,-1,-1,0,2,1,-1,-2,-2,-1,1,2};
int dy[] = { 1,0,-1,-1,-1,0,1,1,-1,-2,-2,-1,1,2,2,1};

class ChessMetric
{
public:
    long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
    {
        int x,y,i,j;
        int sx = start[0],sy=start[1],ex = end[0],ey = end[1];
        ways[sy][sx][0] = 1;

        for(i = 1; i<= numMoves; i++)
        {
            for(x=0;x<size;x++)
            {
                for(y=0;y<size;y++)
                {
                    for(j=0;j<16;j++)
                    {
                        int nx= x + dx[j];
                        int ny = y+ dy[j];

                        if(nx< 0 || ny<0 ||nx>=size||ny>=size)
                        {
                            continue;
                        }

                        ways[ny][nx][i] += ways[y][x][i-1];
                    }

                }
            }
        }
        return ways[ey][ex][numMoves];
    }
};

int main ()
{
    // cout<<ChessMetric().howMany(3,{0,0},{1,0},1)<<endl;//1
    // cout<<ChessMetric().howMany(3,{0,0},{1,2},1)<<endl;//1
    // cout<<ChessMetric().howMany(3,{0,0},{2,2},1)<<endl;//0
    // cout<<ChessMetric().howMany(3,{0,0},{0,0},2)<<endl;//5
    cout<<ChessMetric().howMany(100,{0,0},{0,99},50)<<endl;//243097320072600
    return 0;
}