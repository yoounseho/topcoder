#include <vector>
#include <iostream>
//#include <algorithm> //v2

using namespace std;

class KiwiJuiceEasy
{
public:
	KiwiJuiceEasy()
	{

	}

	vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
	{
		for(int i = 0 ; i < fromId.size(); i ++)
		{
	        int f = fromId[i];		
			int t = toId[i];
			bottles[t] += bottles[f];
			bottles[f] = 0;
			if(capacities[t] < bottles[t])
			{
				int refill = bottles[t] - capacities[t];
				bottles[t] = capacities[t];
				bottles[f] = refill;
			}

			//v2
			// int vol = min(bottles[f],capacities[t]-bottles[t]);
			// bottles[f] -= vol;
			// bottles[t] += vol;
		}
		return bottles;
	}
};

int main ()
{
	vector<int> capacities = {14,35,86,58,25,62};
	vector<int> bottles = {6,34,27,38,9,60};
	vector<int> fromId = {1,2,4,5,3,3,1,0};
	vector<int> todoId = {0,1,2,4,2,5,3,1};
	//returns 0, 14, 65, 35, 25, 35
	KiwiJuiceEasy kiwiJuice;
	vector<int> returnValue = kiwiJuice.thePouring(capacities,bottles,fromId,todoId);
	vector<int>::iterator iter;
	for( iter = returnValue.begin(); iter != returnValue.end(); iter++)
		cout<<*iter<<endl;
	return 0;
}