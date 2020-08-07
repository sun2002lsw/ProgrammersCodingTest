#include <string>
#include <stack>

using namespace std;

bool IsCorrect(const string& u)
{
	stack<char> s;

	for (const char c : u)
		if (c == '(')
			s.push(c);
		else // ')'
			if (s.empty())
				return false;
			else
				s.pop();

	return s.empty();
}

string SwapBracketAndPeel(string& u)
{
	for (char& c : u)
		c = (c == '(' ? ')' : '(');

	return string(u.begin() + 1, u.end() - 1);
}

string GetSolution(const string& w)
{
	if (w.empty())
		return w;

	size_t i, balance = (w[0] == '(' ? 1 : -1);
	for (i = 1; balance != 0; i++)
		balance += (w[i] == '(' ? 1 : -1);

	string u(w.begin(), w.begin() + i);
	string v(w.begin() + i, w.end());

	if (IsCorrect(u))
		return u + GetSolution(v);
	else
	{
		string ret = "(" + GetSolution(v) + ")";
		return ret + SwapBracketAndPeel(u);
	}
}

string solution(string p) {
	return GetSolution(p);
}

int main()
{
	string p = "()))((()";
	string answer = solution(p);

	return 0;
}