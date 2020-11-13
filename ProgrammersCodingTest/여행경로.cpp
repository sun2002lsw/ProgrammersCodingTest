#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using TicketInfo = pair<string, bool>;
map<string, vector<TicketInfo>> ticketMap;
vector<string> route;

bool IsAllTicketUsed()
{
	for (const auto& ticket : ticketMap)
		for (const auto& ticketInfo : ticket.second)
			if (ticketInfo.second == false)
				return false;

	return true;
}

bool Travel(const string& start)
{
	for (auto& ticketInfo : ticketMap[start])
		if (!ticketInfo.second)
		{
			route.push_back(ticketInfo.first);
			ticketInfo.second = true;

			if (Travel(ticketInfo.first))
				return true;

			ticketInfo.second = false;
			route.pop_back();
		}

	return IsAllTicketUsed();
}

vector<string> solution(vector<vector<string>> tickets) {
	for (const auto& ticket : tickets)
	{
		const string& start = ticket[0];
		const string& end	= ticket[1];

		ticketMap[start].push_back(TicketInfo(end, false));
	}

	for (auto& ticket : ticketMap)
		sort(ticket.second.begin(), ticket.second.end());

	route.push_back("ICN");
	Travel("ICN");

	return route;
}

int main()
{
	vector<vector<string>> tickets = { {"ICN", "A"}, {"A", "B"}, {"B", "ICN"} };

	solution(tickets);

	return 0;
}
