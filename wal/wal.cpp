#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 10;
pair<int, int> robots[MAXN];

int findMin(int start, int stop, int comp) {
	int minIndex = start;
	for (int i = start+1; i < stop+1; i++) {
		if (robots[i].second < comp && robots[i].second < robots[minIndex].second) {
			minIndex = i;
		}
	}
	if (robots[minIndex].second > comp)
		return -1;
	return minIndex;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int s, z;
		cin >> s >> z;
		robots[i] = make_pair(s, z);
	}

	sort(robots + 1, robots + n + 1);

	for (int i = 1; i < n; i++) {
		if (robots[i].first == -1) continue;
		int result = findMin(i+1, n, robots[i].second);
		robots[i].first = -1;
		if (result != -1)
			robots[result].first = -1;
	}
	if (robots[n].first == -1)
		cout << "TAK";
	else
		cout << "NIE";

}