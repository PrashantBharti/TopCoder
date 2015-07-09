#include <iostream>
#include <vector>
using namespace std;

class ANDEquation
{
public:
	static int restoreY(vector<int> &vcInput);
};

/*static*/ int ANDEquation::restoreY(vector<int> &vcInput)
{
if (vcInput.size() < 3 || vcInput.size() > 50)
	return -1;

vector<int> vcInputTemp(vcInput);
vector<int>::iterator iter = vcInputTemp.begin();
while (vcInputTemp.size() > 1)
	{
	if ((*iter & *(iter + 1)) == *iter)
		vcInputTemp.erase(iter + 1);
	else if ((*iter & *(iter + 1)) == *(iter + 1))
		vcInputTemp.erase(iter);
	else
		vcInputTemp.erase(iter, iter + 2);

	iter = vcInputTemp.begin();
	}

iter = vcInput.begin();
bool IsFirst = true;
while (vcInput.size() > 1)
	{
	if (IsFirst && *iter == vcInputTemp[0])
		{
		IsFirst = false;
		vcInput.erase(iter);
		}
	else if (IsFirst && *(iter + 1) == vcInputTemp[0])
		{
		IsFirst = false;
		vcInput.erase(iter + 1);
		}

	iter = vcInput.begin();
	*iter = (*iter & *(iter + 1));
	vcInput.erase(iter + 1);
	}

return vcInputTemp[0] == vcInput[0] ? vcInput[0] : -1;
}

int main(int argc, char *argv[])
{
vector<int> vcInput;
vcInput.push_back(2);
vcInput.push_back(3);
vcInput.push_back(7);
vcInput.push_back(19);

int ret = ANDEquation::restoreY(vcInput);
cout << "Value is: " << ret << endl;

char temp;
cin >> temp;

return 0;
}