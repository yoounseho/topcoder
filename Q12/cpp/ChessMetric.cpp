#include <iostream>
#include <vector>
using namespace std;

class ChessMetric
{
public:
    vector<vector<int>> movement;

    long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
    {
        movement = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1},{2,1},{1,2},{2,-1},{1,-2},{-1,-2},{-2,-1},{-1,2},{-2,1}};
        long long sumMovements = 0;
        if(numMoves > 0 )
        {
            for(int i = 0 ; i < movement.size() ; i++)
            {
                countMove(size,start,end,numMoves,i, sumMovements);
            }
        }

        return sumMovements;
    }

    void countMove(int size, vector<int> cur, vector<int> end, int leftMoves, int movementIndex, long long& count)
    {
        cout<<cur[0]<<" , "<<cur[1]<< " : "<<leftMoves<<endl;

        if(movementIndex == 0)
            return;

        int x = movement[movementIndex][0];
        int y = movement[movementIndex][1];

        cur[0] += x;
        cur[1] += y;

        if((cur[0] >= 0 && cur[0] < size) && (cur[1] >= 0 && cur[1] < size))                
        {
            if(leftMoves - 1 == 0 && (cur[0] == end[0] && cur[1] == end[1]))
            {
                //도착
                count += 1;
                cout<< "counting : " << count<<endl;
            }
            else
            {
                if(leftMoves-1 > 0)
                {
                    for(int l = 0; l < movement.size(); l++)
                        countMove(size, cur, end, leftMoves -1,l,count);
                }
            }
            
        }


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