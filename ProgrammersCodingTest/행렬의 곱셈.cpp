#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	size_t rowSize = arr1.size();
	size_t colSize = arr2[0].size();
	vector<vector<int>> answer(rowSize, vector<int>(colSize));

	for (size_t i = 0; i < rowSize; i++)
		for (size_t j = 0; j < colSize; j++)
		{
			answer[i][j] = 0;
			for (size_t k = 0; k < arr1[0].size(); k++)
				answer[i][j] += arr1[i][k] * arr2[k][j];
		}

	return answer;
}
