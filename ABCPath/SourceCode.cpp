#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class ABCPath
{
public:
	static int length(vector<string> &grid);

private:
	static bool fillAposlist(const vector<string> &grid, vector<pair<int, int>> &Aposlist);
	static int findpathlength(const vector<string> &grid, const pair<int, int> &pos, const pair<int, int> &posprev, map<pair<int, int>, int> &prevlengths);
	static int testnext(const vector<string> &grid, const pair<int, int> &pos, const pair<int, int> &prevpos, const pair<int, int> &testpos, map<pair<int, int>, int> &prevlengths);
};

/*static*/ bool ABCPath::fillAposlist(const vector<string> &grid, vector<pair<int, int>> &Aposlist)
{
for(unsigned int i = 0; i < grid.size(); i++)
	{
	if(grid[i].size() > 50 || grid[i].size() < 1)
		return false;

	for(unsigned int j = 0; j < grid[i].size(); j++)
		{
		if(grid[i][j] < 'A' || grid[i][j] > 'Z')
			return false;

		if(grid[i][j] == 'A')
			Aposlist.push_back(pair<int, int>(i, j));

		}
	}

return true;
}

/*static*/ int ABCPath::testnext(const vector<string> &grid, const pair<int, int> &pos, const pair<int, int> &prevpos, const pair<int, int> &testpos, map<pair<int, int>, int> &prevlengths)
{
int leftlimit = 0;
int toplimit = 0;
int rightlimit = grid[0].size() - 1;
int bottomlimit = grid.size() - 1;

int pathlength = 0;

if(testpos.first >= toplimit && testpos.first <= bottomlimit && testpos.second >= leftlimit && testpos.second <= rightlimit && prevpos != testpos)
	{
	if(grid[testpos.first][testpos.second] == 1 + grid[pos.first][pos.second] && grid[testpos.first][testpos.second] <= 'Z')
		{
		if(prevlengths[testpos] != 0)
			pathlength = prevlengths[testpos];
		else
			{
			pathlength = findpathlength(grid, testpos, pos, prevlengths);
			prevlengths[testpos] = pathlength;
			}
		}
	}

return pathlength;
}

/*static*/ int ABCPath::findpathlength(const vector<string> &grid, const pair<int, int> &pos, const pair<int, int> &posprev, map<pair<int, int>, int> &prevlengths)
{
int maxpathlength = 0;

// check pos1
pair<int, int> pos01(pos.first-1, pos.second-1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos01, prevlengths));

// check pos2
pair<int, int> pos02(pos.first-1, pos.second);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos02, prevlengths));

// check pos3
pair<int, int> pos03(pos.first-1, pos.second+1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos03, prevlengths));

// check pos4
pair<int, int> pos10(pos.first, pos.second-1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos10, prevlengths));

// check pos5
pair<int, int> pos13(pos.first, pos.second+1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos13, prevlengths));

// check pos6
pair<int, int> pos20(pos.first+1, pos.second-1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos20, prevlengths));

// check pos7
pair<int, int> pos21(pos.first+1, pos.second);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos21, prevlengths));

// check pos8
pair<int, int> pos22(pos.first+1, pos.second+1);
maxpathlength = max(maxpathlength, ABCPath::testnext(grid, pos, posprev, pos22, prevlengths));

return 1 + maxpathlength;
}

/*static*/ int ABCPath::length(vector<string> &grid)
{
if(grid.size() > 50 || grid.size() < 1)
	return 0;

vector<pair<int, int>> Aposlist;

bool ret = ABCPath::fillAposlist(grid, Aposlist);
if(!ret)
	return 0;

int maxlen = 0;
map<pair<int, int>, int> prevlengths;

for(unsigned int i = 0; i < Aposlist.size(); i++)
	{
	int len = findpathlength(grid, Aposlist[i], pair<int, int> (-1, -1), prevlengths);
	if(len > maxlen)
		maxlen = len;
	}

return maxlen;
};

int main(int argc, char *argv[])
{
vector<string> grid;
grid.push_back("AMNOPA");
grid.push_back("ALEFQR");
grid.push_back("KDABGS");
grid.push_back("AJCHUT");
grid.push_back("AAIWVA");
grid.push_back("AZYXAA");

int length = ABCPath::length(grid);
cout << "Max path length is: " << length << endl;

char temp;
cin >> temp;

return 0;
}