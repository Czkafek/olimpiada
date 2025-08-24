#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
vector<int> neighbors[MAXN];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		neighbors[n1].push_back(n2);
		neighbors[n2].push_back(n1);
	}

	for (int i = 1; i < n + 1; i++) {
		if (neighbors[i].empty())
			cout << "Wiewior sam!";
		else {
			sort(neighbors[i].begin(), neighbors[i].end());
			for (int neighbor : neighbors[i])
				cout << neighbor << " ";
		}
		cout << '\n';
	}

}