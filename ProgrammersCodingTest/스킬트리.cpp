#include <string>
#include <vector>

using namespace std;

bool IsPossible(string skill, const string& skillTree)
{
	for (int curSkill = 0, i = 0; i < skillTree.size(); i++)
		if (skill.find(skillTree[i]) != string::npos)
			if (skill[curSkill] != skillTree[i])
				return false;
			else
				curSkill++;

	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (const string& skillTree : skill_trees)
		if (IsPossible(skill, skillTree))
			answer++;

	return answer;
}

int main()
{
	string skill = "CBD";
	vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

	solution(skill, skill_trees);

	return 0;
}
