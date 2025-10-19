#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e6 + 10;

set<pair<ll, ll>> substances;
pair<int, pair<pair<ll, ll>, pair<ll, ll>>> results[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		int tmp;
		cin >> tmp;
		substances.insert({ tmp, i });
	}

	// Sortujemy raz na początku i następnie wykonujemy pętle aż do skończenia się substancji 
	// lub aż do zostania jednej substancji lub aż do skońćzenia się pojemników

	
	int i = 1;
	while (i < n && !substances.empty()) {
		results[i].second.first.first = substances.begin()->second;
		if (substances.size() == 1) {
			results[i].first = 1;
			set<pair<ll, ll>>::iterator sub = substances.begin();
			if (sub->first >= k) {
				if (sub->first == 0)
					substances.erase(sub);
				else {
					auto it = substances.find({ sub->first, sub->second });
					pair<ll, ll> new_val = { it->first - k, sub->second };
					substances.erase(it);
					substances.insert(new_val);
				}
				results[i].second.first.second = k;
			}
			else {
				results[i].second.first.second = sub->second;
				substances.clear();
			}
		}
		else {
			set<pair<ll, ll>>::iterator sub1 = substances.begin();
			set<pair<ll, ll>>::reverse_iterator sub2 = substances.rbegin();
			int tmpRes = sub1->first - k;
			if (tmpRes < 0) {
				results[i].first = 2;
				results[i].second.second.first = substances.rbegin()->second;
				results[i].second.first.second = substances.begin()->first;
				substances.erase(substances.begin());
				tmpRes = abs(tmpRes);
				if (sub2->first - tmpRes < 0) {
					results[i].second.second.second = substances.rbegin()->first;
					substances.erase(prev(substances.end()));
				}
				else {
					results[i].second.second.second = tmpRes;
					if (sub2->first - tmpRes == 0)
						substances.erase(prev(substances.end()));
					else {
						auto it = substances.find({ substances.rbegin()->first, substances.rbegin()->second });
						pair<ll, ll> new_val = { it->first - tmpRes, substances.rbegin()->second };
						substances.erase(it);
						substances.insert(new_val);
					}
				}
			}
			else {
				results[i].second.first.second = k;
				if (tmpRes == 0)
					substances.erase(prev(substances.end()));
				else {
					auto it = substances.find({ substances.begin()->first, substances.begin()->second });
					pair<ll, ll> new_val = { it->first - k, substances.begin()->second };
					substances.erase(it);
					substances.insert(new_val);
				}
			}
		}
		i++;
	}

	if (substances.empty() && i <= n) {
		cout << "TAK";
		for (int i = 1; i < n + 1; i++) {
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