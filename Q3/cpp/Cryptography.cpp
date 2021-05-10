#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Crytography
{
public:
    long long encrypt(vector<int> numbers)
    {
        //long long 값으로 들어오는데 int로 처리하고있으니 정상적인값이 안들어옴.
        //int maximum = 0;
        long long maximum = 0;
        vector<int> temp(numbers);
        for(int i = 0; i<temp.size();i++)
        {
            temp[i] +=1;
            //long long 값으로 들어오는데 int로 처리하고있으니 정상적인값이 안들어옴.
            //int value = 0;
            long long value = 1;
            for(int l = 0; l<temp.size();l++)
            {
                value *= temp[l];
            }
            maximum = max(maximum,value);
            temp[i] -=1;
        }
        return maximum;
    }
};

int main()
{
    vector<int> numbers = {1000,999,998,997,996,995};
    cout<<Crytography().encrypt(numbers)<<endl;
    return 0;
}