#include <iostream>

using namespace std;

int n, m;
int a[10][10];
int t[10][10];
int answer;

void up(int x, int y, int flag)
{
	for (int i = y; i >= 1; i--) {
		if (a[i][x] == 6)
			break;
		t[i][x] += flag;
	}
}
void down(int x, int y, int flag)
{
	for (int i = y; i <= n; i++) {
		if (a[i][x] == 6)
			break;
		t[i][x] += flag;
	}
}
void left(int x, int y, int flag)
{
	for (int i = x; i >= 1; i--) {
		if (a[y][i] == 6)
			break;
		t[y][i] += flag;
	}
}
void right(int x, int y, int flag)
{
	for (int i = x; i <= m; i++) {
		if (a[y][i] == 6)
			break;
		t[y][i] += flag;
	}
}

void dfs(int x, int y)
{
	if (x > m) {
		dfs(1, y + 1);
		return;
	}
	if (y > n) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!t[i][j])
					count++;
			}
		}
		if (answer > count)
			answer = count;
		return;
	}
	switch (a[y][x]) {
	case 1:
		// Up
		up(x, y, 1);
		dfs(x + 1, y);
		up(x, y, -1);

		// Down
		down(x, y, 1);
		dfs(x + 1, y);
		down(x, y, -1);

		// Left
		left(x, y, 1);
		dfs(x + 1, y);
		left(x, y, -1);

		// Right
		right(x, y, 1);
		dfs(x + 1, y);
		right(x, y, -1);
		break;
	case 2:
		// Up & Down
		up(x, y, 1);
		down(x, y, 1);
		dfs(x + 1, y);
		up(x, y, -1);
		down(x, y, -1);

		// Left & Right
		left(x, y, 1);
		right(x, y, 1);
		dfs(x + 1, y);
		left(x, y, -1);
		right(x, y, -1);
		break;
	case 3:
		// Up & Right
		up(x, y, 1);
		right(x, y, 1);
		dfs(x + 1, y);
		up(x, y, -1);

		// Right & Down
		down(x, y, 1);
		dfs(x + 1, y);
		right(x, y, -1);

		// Down & Left
		left(x, y, 1);
		dfs(x + 1, y);
		down(x, y, -1);

		// Left & Up
		up(x, y, 1);
		dfs(x + 1, y);
		left(x, y, -1);
		up(x, y, -1);
		break;
	case 4:
		// Up & Left & Right
		up(x, y, 1);
		left(x, y, 1);
		right(x, y, 1);
		dfs(x + 1, y);
		left(x, y, -1);

		// Up & Right & Down
		down(x, y, 1);
		dfs(x + 1, y);
		up(x, y, -1);

		// Right & Down & Left
		left(x, y, 1);
		dfs(x + 1, y);
		right(x, y, -1);

		// Left & Up & Down
		up(x, y, 1);
		dfs(x + 1, y);
		left(x, y, -1);
		up(x, y, -1);
		down(x, y, -1);
		break;
	case 5:
		// Up & Down & Left & Right
		up(x, y, 1);
		down(x, y, 1);
		left(x, y, 1);
		right(x, y, 1);
		dfs(x + 1, y);
		up(x, y, -1);
		down(x, y, -1);
		left(x, y, -1);
		right(x, y, -1);
		break;
	default:
		dfs(x + 1, y);
		break;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 6)
				t[i][j] = true;
		}
	}

	answer = 2147483647;
	dfs(1, 1);
	cout << answer;
}