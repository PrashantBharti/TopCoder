#include <iostream>
#include <string>
using namespace std;

class AB
{
public:
	static string createString(int N, int K);

private:
	static int maxAs(int N, int K);
};

/*static*/ int AB::maxAs(int N, int K)
{
for(int i = 1; i <= N; i++)
	{
	if(K <= i*(N-i))
		return i;
	}

return N;
}

/*static*/ string AB::createString(int N, int K)
{
if(N < 2 || N > 50)
	return "";

if(K < 0 || K > (N*(N-1))/2)
	return "";

int requiredAs = maxAs(N, K);
if(requiredAs >= N)
	return "";

string strAB;
for(int i = 1; i <= N; i++)
	strAB.push_back('B');

for(int i = 0; i < requiredAs - 1; i++)
	strAB[i] = 'A';

int presentPairs = (requiredAs - 1)*(N - requiredAs + 1);
int requiredPairs = K - presentPairs + requiredAs - 1;
int newPos = N - requiredPairs - 1;
strAB[newPos] = 'A';

return strAB;
}

int main(int argc, char *argv[])
{
int N = 0, K = 0;
cout << "N = ";
cin >> N;
cout << "K = ";
cin >> K;

string strAB = AB::createString(N, K);

cout << "String Is: " << strAB << endl;

char temp;
cin >> temp;
return 0;
}