#include <set>
#include <vector>
#include <string>

using namespace std;

bool IsNotSubset(const vector<int>& candidKeyIdxsBitVec, int attrIdxsBit)
{
	for (int i = 0; i < candidKeyIdxsBitVec.size(); i++)
	{
		int candidKeyIdxsBit = candidKeyIdxsBitVec[i];
		if ((candidKeyIdxsBit & attrIdxsBit) == candidKeyIdxsBit)
			return false;
	}

	return true;
}

int solution(vector<vector<string>> relation) {
	int N = relation.size();
	int M = relation[0].size();

	vector<int> candidKeyIdxsBitVec;
	for (int attrIdxsBit = 1; attrIdxsBit < (1 << M); attrIdxsBit++)
	{
		set<string> rowStrSet;

		for (int row = 0; row < N; row++) 
		{
			string rowStr = "";

			for (int attrIdx = 0; attrIdx < M; attrIdx++)
			{
				int attrIdxBit = 1 << attrIdx;
				if (attrIdxsBit & attrIdxBit)
					rowStr += relation[row][attrIdx];
			}

			rowStrSet.insert(rowStr);
		}

		if (rowStrSet.size() != N)
			continue; // not super key

		if (!IsNotSubset(candidKeyIdxsBitVec, attrIdxsBit))
			continue; // not ÃÖ¼Ò¼º

		candidKeyIdxsBitVec.push_back(attrIdxsBit);
	}

	return candidKeyIdxsBitVec.size();
}
