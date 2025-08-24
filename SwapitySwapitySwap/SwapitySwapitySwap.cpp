#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
int cows[MAXN];
bool isChecked[MAXN];
int solution[MAXN];

void turn(int a, int b) {
    while (b > a) {
        int tmp = cows[a];
        cows[a] = cows[b];
        cows[b] = tmp;
        a++;
        b--;
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i < n + 1; i++)
        cows[i] = i;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        turn(l, r);
    }

    vector<int> seq;
    for(int j = 1; j < n+1; j++) {
        if (!isChecked[j]) {
            int current = j;
            while (!isChecked[current]) {
                seq.push_back(current);
                isChecked[current] = true;
                current = cows[current];
            }

            for (int i = 0; i < seq.size(); i++) {
                int index = seq[i];
                int move = k % seq.size();
                int value = seq[(i + move) % seq.size()];
                solution[index] = value;
            }
            seq.clear();
        }
    }
    for (int i = 1; i < n + 1; i++)
        cout << solution[i];
}