#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CorporationSalary
{
public:
    long long totalSalary(vector<string> relations)
    {
        vector<long long> salary = vector<long long>(relations.size(),0);
        
        while (true)
        {
            for(int i =0 ; i<relations.size();i++)
            {
                //급여가 계산된 상태면 더이상 계산할 필요없음.
                if(salary[i] == 0)
                {
                    bool bCheck = false;
                    for(int l = 0 ; l<relations[i].size();l++)
                    {
                        if(relations[i].substr(l,1) == "Y")
                        {
                            //아직 부하급여가 계산이 안되었다면 계산할 필요없음.
                            if(salary[l] == 0)
                            bCheck = true;
                        }
                    }

                    if(!bCheck)
                    {
                        //급여계산시작.
                        int sal = 0 ;
                        bool bFlag = false;
                        for( int l = 0; l<relations[i].size();l++)
                        {
                            if(relations[i].substr(l,1) == "Y")
                            {
                                bFlag = true;
                                sal += salary[l];
                            }
                        }
                        if(!bFlag)
                            sal = 1;
                        salary[i] = sal;
                    }
                }
            }

            //탈출조건 계산
            int condition = 1;
            vector<long long>::iterator it;
            for(it = salary.begin(); it != salary.end(); it++)
                condition *= *it;

            //디버깅
            vector<long long>::iterator it_;
            for(it_ = salary.begin(); it_ != salary.end(); it_++)
                cout<<*it_<<" ";
            cout<<"==============================="<<endl;

            if(condition != 0)
                break;
        }
        

        int sum = 0;
        vector<long long>::iterator it;
        for(it = salary.begin(); it != salary.end(); it++)
            sum += *it;
        return sum;
    }

};

int main()
{
    vector<string> relations_1 = {"N"};//1
    vector<string> relations_2 = {"NNYN","NNYN","NNNN","NYYN"};//5
    vector<string> relations_3 = {"NNNNNN","YNYNNY","YNNNNY","NNNNNN","YNYNNN","YNNYNN"};//17
    vector<string> relations_4 = {"NYNNYN","NNNNNN","NNNNNN","NNYNNN","NNNNNN","NNNYYN"};//8
    vector<string> relations_5 = {"NNNN","NNNN","NNNN","NNNN"}; //4

    cout<<CorporationSalary().totalSalary(relations_1)<<endl;
    cout<<CorporationSalary().totalSalary(relations_2)<<endl;
    cout<<CorporationSalary().totalSalary(relations_3)<<endl;
    cout<<CorporationSalary().totalSalary(relations_4)<<endl;
    cout<<CorporationSalary().totalSalary(relations_5)<<endl;
    return 0;
}