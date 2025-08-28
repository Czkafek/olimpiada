#include <bits/stdc++.h>
using namespace std;

const int MAXK = 50 + 10;
string models[MAXK];

void solveModel(int index) {
	string model = 'S' + models[index];
	int l = 0, r = 0;
	int healthy = 0, L_infected = 0, P_infected = 0;
	while (++r < model.length()) {
		if (model[r] == 'P') {
			P_infected++;
			if (model[l] == 'P')
				P_infected += r - l - 1;
			else
				healthy += r - l - 1;
			l = r;
		}
		else if (model[r] == 'L') {
			L_infected++;
			if (model[l] == 'P') {
				L_infected += (r - l - 1) / 2;
				P_infected += (r - l - 1) / 2;
				healthy += (r - l - 1) % 2;
			}
			else
				L_infected += r - l - 1;
			l = r;
		}
	}
	if (model[l] == 'P')
		P_infected += r - l - 1;
	else
		healthy += r - l - 1;

	cout << L_infected << " " << P_infected << " " << healthy << "\n";
}


int main()
{
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a >> models[i];
	}

	for (int i = 0; i < k; i++)
		solveModel(i);
}