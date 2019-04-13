#include <iostream>

using namespace std;

int n, m;
int a[10][10];
int t[10][10];

void dfs(int x, int y) {
	int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
	for (int i = 0; i < 4; i++) {
		int to_x = x + to[1][i];
		int to_y = y + to[0][i];

		if (to_x < 1 || to_y < 1 || to_x > m || to_y > n)
			continue;

		if (t[to_y][to_x] == 0) {
			t[to_y][to_x] = 2;
			dfs(to_x, to_y);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int answer = 0;
	for (int fy = 1; fy <= n; fy++) {
		for (int fx = 1; fx <= m; fx++) {
			if (a[fy][fx] != 0)
				continue;
			for (int sy = 1; sy <= n; sy++) {
				for (int sx = 1; sx <= m; sx++) {
					if (fy == sy && fx == sx)
						continue;
					if (a[sy][sx] != 0)
						continue;
					for (int ty = 1; ty <= n; ty++) {
						for (int tx = 1; tx <= m; tx++) {
							if (fy == ty && fx == tx)
								continue;
							if (sy == ty && sx == tx)
								continue;
							if (a[ty][tx] != 0)
								continue;

							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++)
									t[i][j] = a[i][j];
							}

							t[fy][fx] = t[sy][sx] = t[ty][tx] = 1;


							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									if (t[i][j] == 2)
										dfs(j, i);
								}
							}

							int count = 0;
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									if (t[i][j] == 0)
										count++;
								}
							}
							if (answer < count)
								answer = count;
						}
					}
				}
			}
		}
	}
	cout << answer;
}