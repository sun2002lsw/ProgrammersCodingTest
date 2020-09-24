#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, time_t> cache;

void DeleteLRUcache()
{
	if (cache.empty())
		return;

	string LRUcity;
	time_t LRUtime = 987654321;

	for (const auto& cacheData : cache)
		if (LRUtime > cacheData.second)
		{
			LRUtime = cacheData.second;
			LRUcity = cacheData.first;
		}

	cache.erase(cache.find(LRUcity));
}

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0)
		return 5 * cities.size();

	for (string& city : cities)
		for (char& c : city)
			c = tolower(c);

	int missCnt = 0;
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (cache.find(cities[i]) == cache.end())
		{
			missCnt++;
			if (cache.size() == cacheSize)
				DeleteLRUcache();
		}

		cache[cities[i]] = i;
	}

	return cities.size() + 4 * missCnt;
}

int main()
{
	int cacheSize = 0;
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

	solution(cacheSize, cities);

	return 0;
}