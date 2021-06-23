#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class BadNeighbors
{
public:
    int maxDonations(vector<int> donations)
    {
        return max(GetSum(donations,0),GetSum(donations,1));
    }
    
    int GetSum(vector<int> donations, int startIndex)
    {
        vector<int> sum = vector<int>(donations.size(),0);
        bool bLastFlag = startIndex == 0 ? true : false;

        // //계산 미스가 발생되지 않게 하기위해 미리 startindex 이전값들을 세팅
        // for(int l = 0 ; l < startIndex ; l++)
        //     sum[l] = donations[startIndex];

        int correction = 0;
        switch (startIndex)
        {
        case 0:
            correction = -1;
            break;
        case 1:
            correction = 0;
            break;
        default:
            break;
        }
        for(int i = startIndex ; i<donations.size() + correction ; i++)
        {
            if(i - 2 >= 0)
            {
                if(donations[i] + sum[i-2] > sum[i-1])
                    sum[i] = donations[i] + sum[i-2];
                else
                    sum[i] = sum[i-1]; 
            }
            else if( i - 1 >= 0)
            {
                if(sum[i-1] < donations[i])
                    sum[i] = donations[i];
                else
                    sum[i] = sum[i-1];
            }
            else
            {
                //첫번째 인덱스
                sum[i] = donations[i];
            }
            
        }

        int maxsum = 0;
        for(int l = 0 ; l<sum.size();l++)
        {
            maxsum = max(maxsum,sum[l]);
            //cout<< sum[l] <<" "; // 디버깅
        }
        //cout<<endl; // 디버깅


        return maxsum;
    }
};

int main ()
{
    vector<int> donations_1 = {10,3,2,5,7,8};
    vector<int> donations_2 = {11,15};
    vector<int> donations_3 = {7,7,7,7,7,7,7};
    vector<int> donations_4 = {1,2,3,4,5,1,2,3,4,5};
    vector<int> donations_5 = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72}; //2926
    
    cout<<BadNeighbors().maxDonations(donations_1)<<endl;
    cout<<BadNeighbors().maxDonations(donations_2)<<endl;
    cout<<BadNeighbors().maxDonations(donations_3)<<endl;
    cout<<BadNeighbors().maxDonations(donations_4)<<endl;
    cout<<BadNeighbors().maxDonations(donations_5)<<endl;
    return 0;
}