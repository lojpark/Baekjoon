#include <iostream>

using namespace std;

int n, m, h;
bool a[40][20];
int answer;

int ladder(int x, int y)
{
	if (y > h) {
		return x;
	}
	if (a[y][x]) {
		return ladder(x + 1, y + 1);
	}
	if (x > 1 && a[y][x - 1]) {
		return ladder(x - 1, y + 1);
	}
	return ladder(x, y + 1);
}

void dfs(int x, int y, int count)
{
	if (count > 3)
		return;
	if (x >= n) {
		dfs(1, y + 1, count);
		return;
	}
	if (y > h) {
		for (int i = 1; i <= n; i++) {
			if (ladder(i, 1) != i)
				return;
		}
		if (answer > count)
			answer = count;
		return;
	}

	if (a[y][x] || (x > 1 && a[y][x - 1]) || (x < n - 1 && a[y][x + 1])) {
		dfs(x + 1, y, count);
		return;
	}

	a[y][x] = true;
	dfs(x + 1, y, count + 1);
	a[y][x] = false;
	dfs(x + 1, y, count);
}

int main()
{
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		a[input1][input2] = true;
	}

	answer = 2147483647;
	dfs(1, 1, 0);
	if (answer == 2147483647)
		cout << "-1";
	else
		cout << answer;
}