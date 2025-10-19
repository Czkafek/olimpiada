#include <bits/stdc++.h>
using namespace std;


vector<tuple<int, int, int>> edges;
vector<int> point;
vector<int> sizes;
vector<bool> vertical_result; // pion 
vector<bool> horizontal_result;

int Find(int a) {
	return point[a] == a ? a : point[a] = Find(point[a]);
}

void Union(int a, int b) {
	int x = Find(a), y = Find(b);
	if (x == y) return;
	if (sizes[x] > sizes[y]) swap(x, y);
	point[x] = y;
	sizes[y] += sizes[x];
}

int main()
{
	int n, m, cis_counter = 0;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < t.size(); j++) {
			int weight = 0;
			if (t[j] == 'C')
				weight = 1;
			edges.push_back(make_tuple(weight, i * n + j, i * n + j + 1));
			cis_counter += weight;
			vertical_result.push_back(0);
		}
	}
	for (int i = 0; i < m - 1; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < t.size(); j++) {
			int weight = 0;
			if (t[j] == 'C')
				weight = 1;
			edges.push_back(make_tuple(weight, i * n + j, i * n + j + n));
			cis_counter += weight;
			horizontal_result.push_back(0);
		}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			point.push_back(i * n + j);
			sizes.push_back(0);
		}

	sort(edges.begin(), edges.end(), greater<>());


	int counter = 0;

	while (counter < n * m - 1) {
		int weight = get<0>(edges.back());
		int a = get<1>(edges.back()), b = get<2>(edges.back());
		int x = Find(a);
		int y = Find(b);

		if (x != y) {
			Union(x, y);
			counter++;
			if (a + 1 == b) {
				// pion
				int index = a - (a / n);
				vertical_result[index] = true;
			}
			else {
				int index = a;
				horizontal_result[index] = true;
			}
			cis_counter -= weight;
		}

		edges.pop_back();
	}

	cout << (n - 1) * m + (m - 1) * n - (n * m - 1) << " " << cis_counter;
	for (int i = 0; i < m; i++) {
		cout << "\n";
		for (int j = 0; j < n-1; j++) {
			if (vertical_result[i * (n - 1) + j])
				cout << ".";
			else
				cout << "Z";
		}
	}
	for (int i = 0; i < m-1; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++) {
			if (horizontal_result[i * n + j])
				cout << ".";
			else
				cout << "Z";
		}
	}
	cout << "\n";


}