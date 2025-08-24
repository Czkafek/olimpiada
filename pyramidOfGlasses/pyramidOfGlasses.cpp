#include <bits/stdc++.h>
using namespace std;

long long int glasses[11][10];

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);

	int n = 0, count = 0;
	long long int t = 0;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			glasses[i][j] = 0;
		}
	}

	glasses[0][0] = t * 512;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (glasses[i][j] >= 512) {
				count++;
				long long int value = (glasses[i][j] - 512) / 2;
				glasses[i + 1][j] += value;
				glasses[i + 1][j + 1] += value;
			}
		}
	}

	cout << count;
}