#include <iostream>
#include <string>
using namespace std;

class ABC
{
public:
	static string createString(int N, int K);

private:
	static int maxAs(int N, int K);
	static int maxCs(int N, int K, int givenAs);
};

/*static*/ int ABC::maxAs(int N, int K)
{
for(int i = 0; i <= N; i++)
	{
	// If previous value was the floor value
	if(i*(N - i) > K)
		return i - 1;

	// If previous value was generating maximum pairs
	if(i*(N - i) <= (i - 1)*(N - i + 1))
		return i - 1;
	}

return N;
}

/*static*/ int ABC::maxCs(int N, int K, int givenAs)
{
int givenBs = N - givenAs;

for(int i = 1; i <= givenBs; i++)
	{
	// If new pairs satisfies the remaining pairs
	if(i*(givenBs - i) >= K)
		return i;
	}

return givenBs;
}

/*static*/ string ABC::createString(int N, int K)
{
// Test N for limits
if(N < 3 || N > 30)
	return "";

// Test K for limits
if(K < 0 || K > (N*(N-1)/2))
	return "";

// Maximum As required to create pairs <= K
// As >= 0
int requiredAs = maxAs(N, K);

// Maximum Cs required to create pairs >= present pairs
// Cs >= 1
int requiredCs = maxCs(N, K - requiredAs*(N - requiredAs), requiredAs);

// If K is too large
if(requiredAs + requiredCs >= N)
	return "";

// Create a potential string of Bs
string strABC;
for(int i = 0; i < N; i++)
	strABC.push_back('B');

// Place all As in the potential string
if(requiredAs == 0)
	{
	// BBBBBCCCCCA
	strABC[N-1] = 'A';

	for(int i = 1; i < requiredCs; i++)
		strABC[N - i - 1] = 'C';
	}
else
	{
	// AAAABBBBBCCCCC
	for(int i = 0; i < requiredAs; i++)
		strABC[i] = 'A';

	for(int i = 1; i < requiredCs; i++)
		strABC[N - i] = 'C';
	}

int pairABs = requiredAs == 0 ? 0 : (requiredAs*(N - requiredAs - requiredCs + 1));
int pairACs = requiredAs*(requiredCs - 1);
int pairBCs = (requiredCs - 1)*(N - requiredAs - requiredCs + 1);

int leftBCs = K - pairABs - pairACs - pairBCs;
strABC[requiredAs + leftBCs] = 'C';

return strABC;
}

int main(int argc, char *argv[])
{
int N = 0;
cout << "N = ";
cin >> N;

int K = 0;
cout << "K = ";
cin >> K;

string strABC = ABC::createString(N, K);
cout << "String is: " << strABC << endl;

char temp;
cin >> temp;
return 0;
}