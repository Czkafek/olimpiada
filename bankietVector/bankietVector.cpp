#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000 + 10;
vector<int> onLeft;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	fstream plik;
	plik.open("test1.in", ios::in);

	int n, start = 0, current = 1, tables = 0;
	onLeft.push_back(0);
	plik >> n;
	for (int j = 0; j < n; j++) {
		int tmp;
		plik >> tmp;
		onLeft.push_back(tmp);
	}
	plik.close();

	for (int i = 1; i < n + 1; i++) {
		start = i;
		current = i;
		while (true) {
			if (onLeft.at(current) < start) {
				break;
			}
			if (onLeft.at(current) == start) {
				tables++;
				break;
			}
			current = onLeft.at(current);
		}
	}
	cout << tables << endl;
}

// Jeśli dojdziemy do liczby która jest mniejsza od startowej to oznacza,
// że się cofneliśmy i sprawdzamy już sprawdzony stolik