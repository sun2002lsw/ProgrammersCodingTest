#include <vector>

using namespace std;

bool IsAllSame(const vector<vector<int>>& arr, int val)
{
	for (const vector<int>& row : arr)
		for (const int num : row)
			if (num != val)
				return false;

	return true;
}

pair<int, int> GetCnt(const vector<vector<int>>& arr)
{
	if (arr.size() == 1)
		return arr[0][0] ? make_pair(0, 1) : make_pair(1, 0);

	if (IsAllSame(arr, 0))
		return make_pair(1, 0);
	if (IsAllSame(arr, 1))
		return make_pair(0, 1);

	size_t full = arr.size();
	size_t half = arr.size() / 2;

	vector<vector<int>> arr1(half, vector<int>(half, 0));
	vector<vector<int>> arr2(half, vector<int>(half, 0));
	vector<vector<int>> arr3(half, vector<int>(half, 0));
	vector<vector<int>> arr4(half, vector<int>(half, 0));

	for (size_t i = 0; i < half; i++)
		for (size_t j = 0; j < half; j++)
		{
			arr1[i][j] = arr[i][j];
			arr2[i][j] = arr[i][j + half];
			arr3[i][j] = arr[i + half][j];
			arr4[i][j] = arr[i + half][j + half];
		}

	pair<int, int> arr1Cnt = GetCnt(arr1);
	pair<int, int> arr2Cnt = GetCnt(arr2);
	pair<int, int> arr3Cnt = GetCnt(arr3);
	pair<int, int> arr4Cnt = GetCnt(arr4);

	int zeroCnt = arr1Cnt.first + arr2Cnt.first + arr3Cnt.first + arr4Cnt.first;
	int oneCnt = arr1Cnt.second + arr2Cnt.second + arr3Cnt.second + arr4Cnt.second;

	return make_pair(zeroCnt, oneCnt);
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;

	pair<int, int> cnt = GetCnt(arr);
	answer.push_back(cnt.first);
	answer.push_back(cnt.second);

	return answer;
}

int main()
{
	vector<vector<int>> arr = { {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1} };
	solution(arr);

	return 0;
}