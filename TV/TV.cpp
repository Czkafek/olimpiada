#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5000 + 10;
pair<int, int> houses[MAXN];
bool isUsed[MAXN];
int closest[MAXN];

ll dist(int x, int y) {
	// Metoda Euklidesowa
	ll dx = houses[x].first - houses[y].first;
	ll dy = houses[x].second - houses[y].second;
	return dx * dx + dy * dy;
}
// Metoda Manhatan
//return (abs(houses[x].first - houses[y].first) + abs(houses[x].second - houses[y].second));

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> houses[i].first >> houses[i].second;
		closest[i] = 0;
	}

	isUsed[0] = true;
	int newHouse = 0;
	ll biggestDis = 0;

	for (int i = 0; i < n - 1; i++) {

		ll smallestDis = LLONG_MAX;
		int nextHouse = 0;

		for (int j = 0; j < n; j++) {
			if (!isUsed[j]) {
				ll d = dist(newHouse, j);
				if (d < dist(closest[j], j))
					closest[j] = newHouse;
				ll curDist = dist(closest[j], j);
				if (curDist < smallestDis) {
					smallestDis = curDist;
					nextHouse = j;
				}
			}
		}
		
		newHouse = nextHouse;
		isUsed[newHouse] = true;

		if (smallestDis > biggestDis)
			biggestDis = smallestDis;
	}

	long double sq = sqrt((long double)biggestDis);
	// Można to również zrobić binary searchem
	ll k = (ll)floor(sq);
	while (k * k < biggestDis) ++k;
	while ((k - 1) >= 0 && (k - 1) * (k - 1) >= biggestDis) --k;
	ll result = (ll)k * (ll)(n - 1);

	cout << result;
}