#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000 + 10;
int onLeft[MAXN];
bool isChecked[MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	fstream plik;
	plik.open("test1.in", ios::in);

	int n, start = 0, current = 1, tables = 0;;
	plik >> n;
	for (int j = 1; j < n+1; j++) {
		plik >> onLeft[j];
	}
	plik.close();

	while (true) {
		current = -1;
		for (int i = start+1; i < n + 1; i++) {
			if (isChecked[i] == 0) {
				start = i;
				current = i;
				tables++;
				break;
			}
		}
		if (current == -1) {
			break;
		}
		while (isChecked[current] != 1) {
			isChecked[current] = 1;
			current = onLeft[current];
		}
	}
	cout << tables << endl;
}