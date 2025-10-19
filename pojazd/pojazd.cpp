#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e6 + 10;

deque<pair<ll, ll>> substances;
pair<int, pair<pair<ll, ll>, pair<ll, ll>>> results[MAXN];


int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		int tmp;
		cin >> tmp;
		substances.push_back({ tmp, i });
	}

	// Sortujemy raz na początku i następnie wykonujemy pętle aż do skończenia się substancji 
	// lub aż do zostania jednej substancji lub aż do skońćzenia się pojemników
	
	sort(substances.begin(), substances.end());
	
	int i = 1;
	while (i < n && !substances.empty()) {
		results[i].second.first.first = substances.front().second;
		if (substances.size() == 1) {
			results[i].first = 1;
			pair<int, int> sub = substances.front();
			if (sub.first >= k) {
				if(sub.first == 0)
					substances.pop_front();
				else
					substances.front().second -= k;
				results[i].second.first.second = k;
			}
			else {
				results[i].second.first.second = sub.second;
				substances.pop_front();
			}
		}
		else {
			int sub1 = substances.front().first;
			int sub2 = substances.back().first;
			int tmpRes = sub1 - k;
			if (tmpRes < 0) {
				results[i].first = 2;
				results[i].second.second.first = substances.back().second;
				results[i].second.first.second = substances.front().first;
				substances.pop_front();
				tmpRes = abs(tmpRes);
				if (sub2 - tmpRes < 0) {
					results[i].second.second.second = substances.back().first;
					substances.pop_back();
				}
				else {
					results[i].second.second.second = tmpRes;
					if (sub2 - tmpRes == 0)
						substances.pop_back();
					else
						substances.back().first -= tmpRes;
				}
			}
			else {
				results[i].second.first.second = k;
				if (tmpRes == 0)
					substances.pop_front();
				else
					substances.front().first -= k;
			}
		}
		i++;
	}

	if (substances.empty() && i <= n) {
		cout << "TAK";
		for (int i = 1; i < n+1; i++) {
			if (results[i].first == 0)
				cout << "\n0";
			else if (results[i].first == 1)
				cout << "\n1 " << results[i].second.first.first << " " << results[i].second.first.second;
			else {
				cout << "\n2 " << results[i].second.first.first << " " << results[i].second.first.second;
				cout << " " << results[i].second.second.first << " " << results[i].second.second.second;
			}
		}
	}
	else 
		cout << "NIE";

}