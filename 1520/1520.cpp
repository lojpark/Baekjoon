/*
Dynamic programming(Memoization)
*/
#include <iostream>

using namespace std;

int n, m;
int a[510][510];
int d[510][510];
int to[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

int dfs(int x, int y) 
{
	if (d[y][x] != -1) return d[y][x];

	int i;
	int sum = 0;
	for (i = 0; i < 4; i++) {
		if (y + to[1][i] < 1 || y + to[1][i] > n || x + to[0][i] < 1 || x + to[0][i] > m) continue;
		if (a[y + to[1][i]][x + to[0][i]] < a[y][x]) {
			sum += dfs(x + to[0][i], y + to[1][i]);
		}
	}

	d[y][x] = sum;
	return sum;
}

int main()
{
	int i, j;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}
	
	d[n][m] = 1;
	cout << dfs(1, 1) << endl;

	return 0;
}