#include <string>
#include <vector>

using namespace std;

string IntToString(int line, int n)
{
	string ret;
	for (; line > 0; line /= 2)
		if (line % 2 == 0)
			ret.insert(0, 1, ' ');
		else
			ret.insert(0, 1, '#');

	while (ret.size() < n)
		ret.insert(0, 1, ' ');

	return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int row = 0; row < arr1.size(); row++)
	{
		int line = arr1[row] | arr2[row];
		answer.push_back(IntToString(line, n));
	}

	return answer;
}

int main()
{
	int n = 5;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = {30, 1, 21, 17, 28};

	solution(n, arr1, arr2);

	return 0;
}
