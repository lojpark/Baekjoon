#include <iostream>

using namespace std;

int n;
int a[110][110];
bool v[110][110];
int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int water;

void dfs(int x, int y)
{
	v[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int to_x = x + to[1][i];
		int to_y = y + to[0][i];

		if (to_x < 1 || to_x > n) continue;
		if (to_y < 1 || to_y > n) continue;

		if (a[to_y][to_x] > water && !v[to_y][to_x]) {
			dfs(to_x, to_y);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	int max = 0;
	for (water = 0; water <= 100; water++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = false;
			}
		}

		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > water && !v[i][j]) {
					dfs(j, i);
					count++;
				}
			}
		}
		if (max < count)
			max = count;
	}

	cout << max;
	return 0;
}