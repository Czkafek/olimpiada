#include <bits/stdc++.h>
using namespace std;

const int MAXY = 100;

bool isChecked[MAXY][MAXY];
int result = 0;
int counter = 0;
int x, y, k, m;

void bfs(int a, int b) {

	isChecked[a][b] = true;

	if ((abs(m - (a + b)) < abs(m - result)))
		result = abs(m - (a + b));

	if (counter == k)
		return;

	counter++;

	if (!isChecked[0][b])
		bfs(0, b);
	if (!isChecked[a][0])
		bfs(a, 0);
	if (!isChecked[x][b])
		bfs(x, b);
	if (!isChecked[a][y])
		bfs(a, y);

	int tmpa = max(a - (y - b), 0);
	int tmpb = min(a + b, y);

	if (!isChecked[tmpa][tmpb])
		bfs(tmpa, tmpb);

	tmpa = min(a + b, x);
	tmpb = max(b - (x - a), 0);

	if (!isChecked[tmpa][tmpb])
		bfs(tmpa, tmpb);

	counter--;
	return;
}

int main()
{
	cin >> x >> y >> k >> m;

	bfs(0, 0);

	cout << result;
}