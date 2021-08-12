#include "math.h"
#include <iostream>

using namespace std;

class HandShaking
{
public:
    
    long long countPerfect(int n)
    {
        long long* dp = new long long[n/2+1];

        dp[0] = 1;

        for(int i = 1; i<=n/2; i++)
        {
            dp[i] =0;
            for(int j = 0; j<i;j++)
            {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        long long ans = dp[n/2];
        delete [] dp;
        return ans;
        //카탈란 수
        //c0 = 1
        //c1 = c0c0
        //c2 = c0c1 + c1c0
        //c3 = c0c2 + c1c1 + c2c0
        //c4 = c0c3 + c1c2+ c2c1 + c3c0 
    }
};

int main ()
{
    for(int i = 2 ; i<=50; i = i +2)
        cout<<HandShaking().countPerfect(i)<<endl;
    return 0;
}