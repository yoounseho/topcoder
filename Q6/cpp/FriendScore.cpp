#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class FriendScore
{
public:
    //중복을 피하기 위해서 미리 한번씩 다계산하여 최종적으로 카운팅함.
    int highestScore(vector<string> friends)
    {
        vector<int> friendsNum = vector<int>(friends.size(),0);
        for(int i = 0;i<friends.size();i++)
        {
            vector<int> commonFriends;
            for(int j = 0; j<friends[i].size();j++)
            {
                char y = 'Y';
                if(friends[i].at(j) == y)
                {
                    //friendsNum[i] ++;
                    commonFriends.push_back(j);
                }
            }

            for(int n = 0; n<commonFriends.size();n++)
            {
                for(int m = 0; m<commonFriends.size();m++)
                {
                    if(n!=m)
                    {
                        friends[commonFriends[n]].at(commonFriends[m]) = 'Y';
                    }
                }
            }
        }

        cout<<endl;

        for(int i = 0;i<friends.size();i++)
        {
            for(int j = 0; j<friends[i].size();j++)
            {
                char y = 'Y';
                if(friends[i].at(j) == y)
                {
                    friendsNum[i] ++;
                }
                cout<<friends[i].at(j)<<" ";
            }
            cout<<endl;
        }
        
        int maxNum = 0;
        vector<int>::iterator it;
        for(it = friendsNum.begin() ; it != friendsNum.end(); it++)
        {
            maxNum = max(maxNum,*it);
        }
        return maxNum;
    }
};

int main()
{
    vector<string> friends_1 = {
                                "NNN",
                                "NNN",
                                "NNN"
                             };

    vector<string> friends_2 = {
                                "NYY",
                                "YNY",
                                "YYN"
                             };

    vector<string> friends_3 = {
                                "NYNNN",
                                "YNYNN",
                                "NYNYN",
                                "NNYNY",
                                "NNNYN"
                             };

    vector<string> friends_4 = {
                                "NNNNNNNNNNNNNNY",
                                "NNNNNNNNNNNNNNN",
                                "NNNNNNYNNNNNNNN",
                                "NNNNNNYNNNNNNNY",
                                "NNNNNNNNNNNNNNY",
                                "NNNNNNNNYNNNNNN",
                                "NNNNNNNNNNNNNNN",
                                "NNYYNNNNNNNNNNN",
                                "NNNNNYNNNNNYNNN",
                                "NNNNNNNNNNNNNNY",
                                "NNNNNNNNNNNNNNN",
                                "NNNNNNNNYNNNNNN",
                                "NNNNNNNNNNNNNNN",
                                "NNNNNNNNNNNNNNN",
                                "YNNYYNNNNYNNNNN"
                             };
                             
    cout<<FriendScore().highestScore(friends_1)<<endl;
    cout<<FriendScore().highestScore(friends_2)<<endl;
    cout<<FriendScore().highestScore(friends_3)<<endl;
    cout<<FriendScore().highestScore(friends_4)<<endl;
    return 0;
}