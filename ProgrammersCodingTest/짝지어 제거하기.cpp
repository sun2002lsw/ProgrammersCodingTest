#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
	stack<char> stk;
	for (const char c : s)
		if (stk.empty() || stk.top() != c)
			stk.push(c);
		else
			stk.pop();

	return stk.empty() ? 1 : 0;
}

int main()
{
	string s = "baabaa";
	solution(s);
	return 0;
}