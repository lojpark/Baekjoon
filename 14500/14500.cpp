#include <iostream>

using namespace std;

int n, m;
int a[510][510];
int answer;
bool visit[510][510];

void dfs(int x, int y, int len, int sum)
{
	if (len == 4) {
		if (sum == 20) {
			sum = 20;
		}
		if (answer < sum)
			answer = sum;
		return;
	}

	int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

	for (int i = 0; i < 4; i++) {
		int to_x = x + to[1][i];
		int to_y = y + to[0][i];

		if (to_x < 1 || to_y < 1 || to_x > m || to_y > n)
			continue;
		if (!visit[to_y][to_x]) {
			visit[to_y][to_x] = true;
			dfs(to_x, to_y, len + 1, sum + a[to_y][to_x]);
			visit[to_y][to_x] = false;
		}
	}
}

void t(int x, int y)
{
	int sum = 0;
	sum += a[y][x] + a[y - 1][x] + a[y + 1][x] + a[y][x - 1] + a[y][x + 1];

	sum -= a[y - 1][x];
	if (answer < sum)
		answer = sum;
	sum += a[y - 1][x];
	sum -= a[y + 1][x];
	if (answer < sum)
		answer = sum;
	sum += a[y + 1][x];
	sum -= a[y][x - 1];
	if (answer < sum)
		answer = sum;
	sum += a[y][x - 1];
	sum -= a[y][x + 1];
	if (answer < sum)
		answer = sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = true;
			dfs(j, i, 1, a[i][j]);
			visit[i][j] = false;
			t(j, i);
		}
	}

	cout << answer;
	return 0;
}