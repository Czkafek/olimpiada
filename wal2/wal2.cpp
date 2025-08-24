#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 10;
pair<int, int> robots[MAXN];
bool isUsed[MAXN];

int checkBattle(int index1, int index2) {
	if (robots[index1].first > robots[index2].first && robots[index1].second > robots[index2].second)
		return index1;
	if (robots[index1].first < robots[index2].first && robots[index1].second < robots[index2].second)
		return index2;
	return -1;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> robots[i].first >> robots[i].second;
		isUsed[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < n; j++) {

			while (true) {
				// Coś robi


			}
			if (isUsed[k])
				k++;
			if (isUsed[j] || k == j)
				j++;
			int result = checkBattle(k, j);
			if (result == -1) {
				isUsed[k] = 1;
				isUsed[j] = 1;
			}
			else {

			}

		}
	}


}