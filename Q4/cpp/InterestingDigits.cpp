#include <iostream>
#include <vector>

using namespace std;

class InterestingDigits
{
public:
    vector<int> digits(int base)
    {
        vector<int> returnvalue; 
        for(int n = 2; n< base ; n++)
        {
            bool bSuccessful = true;
            int i = 1;
            while(n*i < 1000)
            {
                //i * n 후 base 진법으로 변환. 각 자리수를 더한다 그리고 n의 배수인지 확인.
                int v = n*i;
                vector<int> converted;
                while(v > base)
                {
                    converted.push_back(v % base);
                    v= v / base;
                }
                converted.push_back(v);
                
                vector<int>::iterator it;
                int sum = 0;
                for(it = converted.begin(); it!=converted.end() ; it++)
                {
                    sum+=*it;
                }   

                if((int)sum/n != (float)sum/n)
                {
                    bSuccessful = false;
                    break;
                }

                i++;
            }

            if(bSuccessful)
                returnvalue.push_back(n);
        }

        return returnvalue;
    }
};

int main ()
{
    int base;
    cin>>base;
    if(base > 0)
    {
        vector<int> returnvalue = InterestingDigits().digits(base);
        vector<int>::iterator it; 
        for(it = returnvalue.begin(); it!=returnvalue.end(); it++)
        {
            if(it != returnvalue.begin())
                cout<<", ";
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}