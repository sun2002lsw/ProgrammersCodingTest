#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<size_t> s;

	for (size_t i = 0; i < prices.size(); s.push(i), i++)
		for (; !s.empty() && prices[i] < prices[s.top()]; s.pop())
			answer[s.top()] = i - s.top();

	for (; !s.empty(); s.pop())
		answer[s.top()] = answer.size() - s.top() - 1;

	return answer;
}

int main()
{
	vector<int> prices = { 1, 2, 3, 2, 3 };

	solution(prices);

	return 0;
}
