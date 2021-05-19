#include <string>
#include <iostream>

using namespace std;

class ThePalindrome
{
public:
    int find(string s)
    {
        int count = 1;
        for(int i = 0 ; i < s.size(); i++)
        {
            count = i;
            bool bDiff = false;
            for(int j = 0; j < s.size() ; j++)
            {
                if(s[j + i] != s[s.size()-1-j])
                {
                    bDiff = true;
                    break;
                }            

                if(j+1 == (int)s.size()/2)
                {
                    break;
                }
            }

            if(!bDiff)
                break;
        }

        return s.size() + count;
    }
};

int main()
{
    cout<<ThePalindrome().find("abab")<<endl;
    cout<<ThePalindrome().find("abacaba")<<endl;
    cout<<ThePalindrome().find("qwerty")<<endl;
    cout<<ThePalindrome().find("abdfhdyrbdbsdfghjkllkjhgfds")<<endl;
    cout<<ThePalindrome().find("abcccc")<<endl;
    return 0;
}