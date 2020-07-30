#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 X에 있다";

	for (size_t i = 0; i < seoul.size(); i++)
		if (seoul[i] == "Kim")
			return answer.replace(answer.find('X'), 1, to_string(i));
}

int main()
{
	vector<string> seoul = { "Jane", "Kim" };
	string ans = solution(seoul);

	return 0;
}
