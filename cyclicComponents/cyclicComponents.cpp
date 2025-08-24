#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

vector<int> G[MAXN];
bool odwiedzone[MAXN];
bool dobry_cykl;

void DFS(int v) {
	odwiedzone[v] = true;
	if (G[v].size() != 2)
		dobry_cykl - false;

	for (size_t i = 0; i < G[v].size(); i++) {
		int u = G[v][i];
		if (!odwiedzone[u])
			DFS(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int wynik = 0;
	for (int i = 1; i <= n; i++) {
		if (!odwiedzone[i]) {
			dobry_cykl = true;
			DFS(i);
			if (dobry_cykl)
				wynik++;
		}
	}

	cout << wynik << "\n";

}