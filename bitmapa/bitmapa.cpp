#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int values[MAXN][MAXN];
int results[MAXN][MAXN];
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			results[i][j] = -1;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			int tmp = line[j] - '0';
			values[i][j+1] = tmp;
			if (tmp == 1) {
				q.push({ i, j + 1 });
				results[i][j + 1] = 0;
			}
		}
	}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		// Góra
		int tmp_i = i-1;
		if (tmp_i > 0 && results[tmp_i][j] == -1) {
			results[tmp_i][j] = results[i][j] + 1;
			q.push({ tmp_i, j });
		}
		
		// Dół
		tmp_i = i + 1;
		if (tmp_i < n+2 && results[tmp_i][j] == -1) {
			results[tmp_i][j] = results[i][j] + 1;
			q.push({ tmp_i, j });
		}

		// Lewo
		int tmp_j = j - 1;
		if (tmp_j > 0 && results[i][tmp_j] == -1) {
			results[i][tmp_j] = results[i][j] + 1;
			q.push({ i, tmp_j });
		}

		// Prawo
		tmp_j = j + 1;
		if (tmp_j < m + 2 && results[i][tmp_j] == -1) {
			results[i][tmp_j] = results[i][j] + 1;
			q.push({ i, tmp_j });
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++)
			cout << results[i][j] << " ";
		cout << "\n";
	}
}