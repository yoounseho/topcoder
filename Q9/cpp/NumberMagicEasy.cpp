#include <iostream>
#include <string>
#include <vector>

using namespace std;

//answer는 4자리 문자열
class NumberMagicEasy
{
public:
    int theNumber(string answer)
    {
        vector<int> card_1 = {1,2,3,4,5,6,7,8};
        vector<int> card_2 = {1,2,3,4,9,10,11,12};
        vector<int> card_3 = {1,2,5,6,9,10,13,14};
        vector<int> card_4 = {1,3,5,7,9,11,13,15};
        vector<int> answervector =vector<int>(16,0);
        vector<vector<int>> cardvector = {card_1,card_2,card_3,card_4};

        for(int i =0 ;i<4;i++)
        {
            int addvalue = 1;
            if(answer.substr(i,1) == "Y")
                addvalue = 1;
            else
                addvalue = -1;

            vector<int> answercard = cardvector[i];
            vector<int>::iterator it;
            for(it = answercard.begin() ; it!=answercard.end();it++)
            {
                answervector[*it - 1] += 1 * addvalue;
            }
        }

        // cout<<"[";
        // for(int i = 0 ; i< answervector.size(); i++)
        //     cout<<answervector[i]<<",";        
        // cout<<"]"<<endl;

        int answerNum = -1;
        for(int i = 0 ; i< answervector.size() ; i++)
        {
            if(answervector[i] > 0)
            {
                if(answerNum == -1)
                    answerNum = i;

                if(answervector[answerNum] <= answervector[i] )
                    answerNum = i;
            }
        }
        
        if(answerNum == -1)
            return 16;
        return answerNum + 1;
    }
};

int main()
{
    cout<< NumberMagicEasy().theNumber("YNYY")<<endl;   
    cout<< NumberMagicEasy().theNumber("YNNN")<<endl;   
    cout<< NumberMagicEasy().theNumber("NNNN")<<endl;   
    cout<< NumberMagicEasy().theNumber("YYYY")<<endl;   
    cout<< NumberMagicEasy().theNumber("NYNY")<<endl;   
    return 0;
}