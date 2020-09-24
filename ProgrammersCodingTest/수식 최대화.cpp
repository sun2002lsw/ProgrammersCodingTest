#include <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void MoveExpiressionToList(string& expression, list<string>& expressionList)
{
	for (size_t i = 0; i < expression.size(); i++)
		if (!isdigit(expression[i]))
		{
			expressionList.push_back(string(expression.begin(), expression.begin() + i));
			expressionList.push_back(string(1, expression[i]));

			expression.erase(0, i + 1);
			return;
		}

	expressionList.emplace_back(move(expression));
}

void CalculateOneOperator(list<string>& expressionList, list<string>::iterator iter)
{
	const auto opIter = iter--;
	const auto lhsIter = iter++; 
	const auto rhsIter = ++iter;

	const char op = (*opIter)[0];
	long long lhs = stoll(*lhsIter);
	long long rhs = stoll(*rhsIter);

	long long val;
	switch (op)
	{
	case '*':
		val = lhs * rhs;
		break;
	case '+':
		val = lhs + rhs;
		break;
	case '-':
		val = lhs - rhs;
		break;
	default:
		val = 0;
		break;
	}

	*opIter = to_string(val);
	expressionList.erase(lhsIter);
	expressionList.erase(rhsIter);
}

void CalculateAllOperator(list<string>& expressionList, const string& op)
{
	while (true)
	{
		const auto iter = find(expressionList.begin(), expressionList.end(), op);
		if (iter == expressionList.end())
			return;

		CalculateOneOperator(expressionList, iter);
	}
}

long long CalculateByOperatorPrecedence(list<string> expressionList, const vector<string>& op)
{
	for (size_t i = 0; i < 3; i++)
		CalculateAllOperator(expressionList, op[i]);

	return abs(stoll(expressionList.front()));
}


long long solution(string expression) {
	vector<string> op = { "*", "+", "-" };

	list<string> expressionList;
	while (expression.size() > 0)
		MoveExpiressionToList(expression, expressionList);

	long long answer = 0;
	do 
	{
		answer = max(answer, CalculateByOperatorPrecedence(expressionList, op));
	} 
	while (next_permutation(op.begin(), op.end()));

	return answer;
}

int main()
{
	string expression = "100-200*300-500+20";
	solution(expression);

	return 0;
}
