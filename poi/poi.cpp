#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 10;
int results[MAXN][MAXN];
int points[MAXN];
tuple<int, int, int> playersScore[MAXN];

int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, t, p;
	cin >> n >> t >> p;

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < t + 1; j++)
			cin >> results[i][j];

	for (int i = 1; i < t + 1; i++) {
		points[i] = 0;
		for (int j = 1; j < n + 1; j++)
			points[i] += results[j][i];
		points[i] = n - points[i];
	}

	for (int i = 1; i < n + 1; i++) {
		int score = 0;
		int amount = 0;
		for (int j = 1; j < t + 1; j++) {
			if (results[i][j] == 1) {
				score += points[j];
				amount++;
			}
		}
		playersScore[i] = make_tuple(score, amount, i);
	}

	sort(playersScore + 1, playersScore + n + 1, [](tuple<int, int, int> a, tuple<int, int, int> b) {
			if (get<0>(a) == get<0>(b)) {
				if (get<1>(a) == get<1>(b))
					return get<2>(a) < get<2>(b);
				return get<1>(a) > get<1>(b);
			}
			return get<0>(a) > get<0>(b);

		});

	for (int i = 1; i < n + 1; i++) {
		if (get<2>(playersScore[i]) == p) {
			cout << get<0>(playersScore[i]) << " " << i;
			break;
		}
	}

}

/*
for (int i = 1; i < n + 1; i++) {
	cout << '\n';
	cout << i << ". ID: " << get<2>(playersScore[i]) << " AMOUNT: " << get<1>(playersScore[i]) << " RESULT: " << get<0>(playersScore[i]);
	cout << '\n';
}
*/