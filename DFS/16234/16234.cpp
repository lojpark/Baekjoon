#include <iostream>
#include <vector>

using namespace std;

int n, l, r;
int a[60][60];
int c[60][60];
bool visit[60][60], check;
int sum, cnt;
int to[2][4] = { { -1, 1, 0, 0 },{ 0, 0, -1, 1 } };

struct Data {
	int x, y;
};
vector<Data> candidate;

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

void unite(int x, int y, int value)
{
	for (int k = 0; k < 4; k++) {
		int to_x = x + to[1][k];
		int to_y = y + to[0][k];

		if (to_x < 1 || to_y < 1 || to_x > n || to_y > n)
			continue;

		int diff = my_abs(a[y][x] - a[to_y][to_x]);
		if (l <= diff && diff <= r && c[to_y][to_x] == 0) {
			check = true;
			c[to_y][to_x] = value;
			unite(to_x, to_y, value);
		}
	}
}

void move(int value)
{
	for (unsigned int i = 0; i < candidate.size(); i++)
		a[candidate[i].y][candidate[i].x] = value;
	candidate.clear();
}

void dfs(int x, int y)
{
	candidate.push_back({ x, y });
	sum += a[y][x];
	cnt++;

	for (int k = 0; k < 4; k++) {
		int to_x = x + to[1][k];
		int to_y = y + to[0][k];

		if (to_x < 1 || to_y < 1 || to_x > n || to_y > n)
			continue;

		if (c[to_y][to_x] == c[y][x] && !visit[to_y][to_x]) {
			visit[to_y][to_x] = true;
			dfs(to_x, to_y);
		}
	}
}

int main()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	int count = 0, answer = 0;
	while (true) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				c[i][j] = 0;
				visit[i][j] = false;
			}
		}

		count = 0;
		check = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i][j] == 0) {
					c[i][j] = ++count;
					unite(j, i, count);
				}
			}
		}

		if (!check)
			break;

		answer++;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i][j] != 0 && !visit[i][j]) {
					sum = cnt = 0;
					visit[i][j] = true;
					dfs(j, i);
					move((int)(sum / cnt));
				}
			}
		}
	}
	cout << answer;
}