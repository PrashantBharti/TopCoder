#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class ASeries
{
public:
	static int longest(vector<int> &vcInput);
};

/*static*/ int ASeries::longest(vector<int> &vcInput)
{
if(vcInput.size() < 2 || vcInput.size() > 50)
	return 0;

sort(vcInput.begin(), vcInput.end());

vector<pair<int, map<int, int>>> vcPossibleAPs;
int maxlength = 0;

vector<int>::reverse_iterator revIter = vcInput.rbegin();
while(revIter != vcInput.rend())
	{
	map<int, int> hashmap;
	hashmap[0] = 1;
	pair<int, map<int, int>> newpair(*revIter, hashmap);

	vector<pair<int, map<int, int>>>::reverse_iterator revIterAPs = vcPossibleAPs.rbegin();
	while(revIterAPs != vcPossibleAPs.rend())
		{
		int diff = revIterAPs->first - *revIter;
		int length = 0;

		if(diff == 0)
			newpair.second = revIterAPs->second;

		if(revIterAPs->second[diff] != 0)
			length = revIterAPs->second[diff] + 1;
		else
			length = 2;

		maxlength = max(maxlength, length);
		newpair.second[diff] = length;

		if(diff == 0)
			break;

		revIterAPs++;
		}

	vcPossibleAPs.push_back(newpair);

	revIter++;
	}

return maxlength;
}

int main(int argc, char *argv)
{
vector<int> vcInput;
vcInput.push_back(3);
vcInput.push_back(8);
vcInput.push_back(4);
vcInput.push_back(5);
vcInput.push_back(6);
vcInput.push_back(2);
vcInput.push_back(2);

int length = ASeries::longest(vcInput);
cout << "Longest AP length" << length << endl;

char temp;
cin >> temp;
return 0;
}