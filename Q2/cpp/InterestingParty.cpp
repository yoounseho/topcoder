#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
//vector가 std namespace 안에 있음.

class InterestingParty
{
public:
  int bestInvitation(vector<string> first, vector<string> second)
  {
    vector<int> interestingCount;

    for(int i = 0 ; i<first.size(); i++)
    {
        int count = 0;
        for(int l = 0; l<first.size();l++)
        {
            if(first[i].compare(first[l]) == 0)
            {
                count++;
            }
        }
        for(int l = 0; l<second.size();l++)
        {
            if(first[i].compare(second[l]) == 0)
            {
                count++;
            }
        }
        interestingCount.push_back(count);
    }

    for(int i = 0 ; i<second.size(); i++)
    {
        int count = 0;
        for(int l = 0; l<first.size();l++)
        {
            if(second[i].compare(first[l]) == 0)
            {
                count++;
            }
        }
        for(int l = 0; l<second.size();l++)
        {
            if(second[i].compare(second[l]) == 0)
            {
                count++;
            }
        }
        interestingCount.push_back(count);
    }

    
    int maxNum = 0;
    for(int i =0 ; i <interestingCount.size();i++)
    {
        maxNum = max(maxNum,interestingCount[i]);
    }
    return maxNum;
  }  
  int bestInvitation_v2(vector<string> first, vector<string> second)
  {
    map<string,int> dic;

    for(int i = 0;i<first.size();i++)
    {
        dic[first[i]]=0;
        dic[second[i]] = 0;
    }

    for(int i =0;i<first.size();i++)
    {
        dic[first[i]]++;
        dic[second[i]]++;
    }

    int ans =0 ;
    map<string,int>::iterator it;

    for(it=dic.begin(); it!= dic.end();it++)
    {
        ans = max(ans,it->second);
    }
    return ans;
  }
};

int main()
{
    vector<string> first = {"snakes","programming","cobra","monty"};
    vector<string> second = {"python","python","anaconda","python"};

    cout<< InterestingParty().bestInvitation_v2(first,second)<<endl;
    return 0;
}