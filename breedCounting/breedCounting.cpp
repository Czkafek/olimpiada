#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;

int cows[MAXN];
pair<int, int> queries[MAXN];
int breed1[MAXN];
int breed2[MAXN];
int breed3[MAXN];


int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n + 1; i++) {
		cin >> cows[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	breed1[0] = 0;
	breed2[0] = 0;
	breed3[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		if (cows[i] == 1) {
			breed1[i] = breed1[i-1] + 1;
			breed2[i] = breed2[i - 1];
			breed3[i] = breed3[i - 1];
		}
		else if (cows[i] == 2) {
			breed1[i] = breed1[i - 1];
			breed2[i] = breed2[i - 1] + 1;
			breed3[i] = breed3[i - 1];
		}
		else {
			breed1[i] = breed1[i - 1];
			breed2[i] = breed2[i - 1];
			breed3[i] = breed3[i - 1] + 1;
		}
	}

	for (int i = 0; i < q; i++) {
		int indexStart = queries[i].first - 1;
		int indexEnd = queries[i].second;
		cout << breed1[indexEnd] - breed1[indexStart];
		cout << " ";
		cout << breed2[indexEnd] - breed2[indexStart];
		cout << " ";
		cout << breed3[indexEnd] - breed3[indexStart];
		cout << endl;
	}
}