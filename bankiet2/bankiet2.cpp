#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000 + 10;
int onLeft[MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	fstream plik;
	plik.open("test1.in", ios::in);

	int n, start = 0, current = 1, tables = 0;;
	plik >> n;
	for (int j = 1; j < n + 1; j++) {
		plik >> onLeft[j];
	}
	plik.close();

	for (int i = 1; i < n + 1; i++) {
		start = i;
		current = i;
		while (true) {
			if (onLeft[current] < start) {
				break;
			}
			if (onLeft[current] == start) {
				tables++;
				break;
			}
			current = onLeft[current];
		}
	}
	cout << tables << endl;
}

// Jeśli dojdziemy do liczby która jest mniejsza od startowej to oznacza,
// że się cofneliśmy i sprawdzamy już sprawdzony stolik