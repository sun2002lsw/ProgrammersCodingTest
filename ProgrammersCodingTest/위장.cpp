#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	unordered_map<string, int> clothesTypeCnt;

	for (const auto& clothe : clothes)
		++clothesTypeCnt[clothe[1]];

	int answer = 1;
	for (const auto& clotheTypeCnt : clothesTypeCnt)
		answer *= clotheTypeCnt.second + 1;

	return answer - 1;
}
