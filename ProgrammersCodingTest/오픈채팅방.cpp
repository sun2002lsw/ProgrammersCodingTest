#include <list>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	string command, uid, nickname;
	unordered_map<string, string> uidToNickname;
	list<pair<string, string>> userCommandList;

	for (const string& log : record) {
		stringstream ss;
		ss.str(log);

		ss >> command;
		ss >> uid;
		if (command != "Leave") {
			ss >> nickname;
			uidToNickname[uid] = nickname;
		}

		if (command != "Change")
			userCommandList.push_back(make_pair(command, uid));
	}

	for (const auto& userCommand : userCommandList) {
		command = userCommand.first;
		uid = userCommand.second;

		if (command == "Enter")
			command = "���� ���Խ��ϴ�.";
		else
			command = "���� �������ϴ�.";

		answer.emplace_back(uidToNickname[uid] + command);
	}

	return answer;
}
