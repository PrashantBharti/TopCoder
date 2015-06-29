#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ABoardGame
{
public:
	static string whoWins(vector<string> &board);

private:
	static int checkPos(char &c);
};

/*static*/ int ABoardGame::checkPos(char &c)
{
if(c == 'A')
	return -1;
else if(c == 'B')
	return 1;
else
	return 0;
}

/*static*/ string ABoardGame::whoWins(vector<string> &board)
{
int N = board.size() / 2;
if(N < 1 || N > 25)
	return "";

int factor = 1;
int row = 0;
int col = 0;
int result = 0; // 0 means draw, < 0 win for A, > 0 win for B
for(int i = 1; i <= N; i++)
	{
	// Limits for L -> R N-i,N-i to N-i,N-i+factor
	row = N - i;
	col = N - i;
	while(col <= N - i + factor)
		{
		result += checkPos(board[row][col]);
		col += 1;
		}

	// Limits for T -> B N-i,N-i+factor to N-i+factor,N-i+factor
	row += 1;
	col -= 1;
	while(row <= N - i + factor)
		{
		result += checkPos(board[row][col]);
		row += 1;
		}

	// Limits for R -> L N-i+factor,N-i+factor to N-i+factor,N-i
	row -= 1;
	col -= 1;
	while(col >= N - i)
		{
		result += checkPos(board[row][col]);
		col -= 1;
		}

	// Limits for B -> T N-i+factor,N-i to N-i,N-i
	row -= 1;
	col += 1;
	while(row >= N - i + 1)
		{
		result += checkPos(board[row][col]);
		row -= 1;
		}

	if(result < 0)
		return "Alice";
	else if(result > 0)
		return "Bob";
	else
		factor += 2;
	}

return "Draw";
}

int main(int argc, char *argv[])
{
vector<string> board;
// {"AAAA", "A.BA", "A..A", "AAAA"}
board.push_back("AAAA");
board.push_back("A.BA");
board.push_back("A..A");
board.push_back("AAAA");

string winner = ABoardGame::whoWins(board);
cout << "Winner is: " << winner.c_str() << endl;

char temp;
cin >> temp;
return 0;
}