#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int numbers[MAXN];
int counter = 0;

int podziel(int l, int r) {
	long long mid = numbers[(l + r) / 2];
	int i = l - 1;
	int j = r + 1;

	while (true) {
		while (numbers[++i] < mid);
		while (numbers[--j] > mid);
		if (i >= j)
			break;
		swap(numbers[i], numbers[j]);
	}
	
	return j;
}
void quickSort(int l, int r, int n) {
	if (l >= r) return;

	int p = podziel(l, r);
	quickSort(l, p, n);
	quickSort(p+1, r, n);
	cout << "\n#" << ++counter << "\n";
	for (int i = 0; i < n; i++)
		cout << numbers[i] << " ";
}



int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	quickSort(0, n-1, n);


	cout << "\n\n\n";

	for (int i = 0; i < n; i++)
		cout << numbers[i] << " ";

}