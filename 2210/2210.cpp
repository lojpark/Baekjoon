#include <iostream>

using namespace std;

int a[10][10];
bool v[1000010];
int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int answer;

void dfs(int x, int y, int value, int len)
{
	if (len == 6) {
		if (!v[value]) {
			v[value] = true;
			answer++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (x + to[1][i] < 1 || x + to[1][i] > 5) continue;
		if (y + to[0][i] < 1 || y + to[0][i] > 5) continue;
		dfs(x + to[1][i], y + to[0][i], value * 10 + a[y + to[0][i]][x + to[1][i]], len + 1);
	}
}

int main()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			dfs(j, i, a[i][j], 1);
		}
	}

	cout << answer;
	return 0;
}