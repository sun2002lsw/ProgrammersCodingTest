#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++)
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			return false;

	return true;
}

int main()
{
	vector<string> phone_book = { "114321", "115", "000"};

	bool answer = solution(phone_book);

	return 0;
}