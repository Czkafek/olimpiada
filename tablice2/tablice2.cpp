#include <bits/stdc++.h>
using namespace std;

// ALGORYTM:
// 1. Mapuję pierwszą tablicę - dla każdej liczby jest przydzielona para<kolumna, wiersz>
// 2. Zaczynam przechodzić się po wszystkich początakch kolumn i wierszy
// 3. Dla każdego początku sprawdzam i zapisuje w tymczasowej zmiennej kolumne/wiersz,
//    który jest przydzielony danej liczbie i sprawdzam czy następne liczby z danej
//    kolumny/wiersza wskazują tą samą liczbę

const int MAXN = 1000;
const int MAXVAL = 2 * 1e6 + 10;
const int CONST_ADDITION = 1e6;
int tab2[MAXN][MAXN];
pair<int, int> coordinates[MAXVAL];
string results[10 + 2];


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {

		bool isAble = true;

		cin >> n >> m; // m - kolumny, n - wiersze

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tmp;
				cin >> tmp;
				coordinates[tmp + CONST_ADDITION] = make_pair(k, j); // <kolumna, wiersz>
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tab2[k][j];
			}
		}

		for (int j = 0; j < m; j++) {
			int colIndex = coordinates[tab2[j][0] + CONST_ADDITION].first;
			for (int k = 0; k < n; k++)
				if (colIndex != coordinates[tab2[j][k] + CONST_ADDITION].first) {
					isAble = false;
					break;
				}
		}

		for (int j = 0; j < n; j++) {
			int colIndex = coordinates[tab2[0][j] + CONST_ADDITION].second;
			for (int k = 0; k < m; k++)
				if (colIndex != coordinates[tab2[k][j] + CONST_ADDITION].second) {
					isAble = false;
					break;
				}
		}

		if (isAble)
			results[i] = "TAK";
		else
			results[i] = "NIE";

	}

	for (int i = 0; i < t; i++) {
		cout << results[i] << '\n';
	}
}

// ALGORYTM 2:
// Wczytuje obydwie tablice, a następnie tworzy z każdego wiersza i kolumny danej tablicy tablice z vectorami
// Na jedną tablice przypadają dwie tablice z maksymalnie 1000 vectorów i każdy vector po maks 1000 int'ów
// Każdy taki vector jest posortowany
// Po dodaniu wszystkich vectorów do tablicy, sortujemy tablice, i następnie porównujemy tablice
// Jeśli tablice są takie same -> wypisujemy "TAK", jeśli nie -> "NIE"
// Funkcja std::sort() ma złożoność czasową O(nlogn), sprawdźmy złożoność czasową sprawdzenia jednej pary tablic dla n = 1000 i m = 1000
// Funkcja sort wykona się dla każdego vectora, vectorów będzie 1000 na jedną tablicę, więc wykona się 4000 sortowań
// Jeden vector ma 1000 elementów, więc posortowanie jednego vectora zajmie około 1000 * 10 = 1e4 operacji
// 4 * 1e3 * 1e4 = 4 * 1e7 -> Mniej więcej złożoność czasowa sprawdzenia jednej pary
// Jeśli będziemy mieli 10 takich par to złożoność czasowa będzie wynosiła:
// 4 * 1e7 * 10 = 4 * 1e8 -> Nie dodaliśmy do tego jeszcze operacji tworzenia tych vectorów, operacji wczytywania i wszystkich innych operacji
// To rozwiązanie nie zmieści się w limicie czasowym