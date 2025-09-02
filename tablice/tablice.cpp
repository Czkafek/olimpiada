#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int MAXN = 1000 + 10;
int table1[MAXN][MAXN];
int table2[MAXN][MAXN];
string results[10 + 1];
unordered_set<int> set1;
unordered_set<int> set2;
pair<int, int> coordinate[2000000 + 10];

int main()
{
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		bool isRight = true;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				cin >> table1[j][k];
				coordinate[table1[j][k] + 1000000] = make_pair(j, k);
			}
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < m; k++)
				cin >> table2[j][k];

		for (int j = 0; j < m; j++) {
			int column = coordinate[table2[0][j] + 1000000].second;
			for (int k = 0; k < n; k++) {
				set1.insert(table1[k][column]);
				set2.insert(table2[k][j]);
			}
			if (set1 != set2) {
				isRight = false;
				break;
			}
			set1.clear();
			set2.clear();
		}
		
		if (!isRight) {
			results[i] = "NIE";
			continue;
		}
		
		for (int j = 0; j < n; j++) {
			int row = coordinate[table2[j][0] + 1000000].first;
			for (int k = 0; k < m; k++) {
				set1.insert(table1[row][k]);
				set2.insert(table2[j][k]);
			}
			if (set1 != set2) {
				isRight = false;
				break;
			}
			set1.clear();
			set2.clear();
		}

		if (isRight)
			results[i] = "TAK";
		else
			results[i] = "NIE";
	}

	for (int i = 0; i < t; i++)
		cout << results[i] << "\n";
}