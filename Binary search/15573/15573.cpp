#include <iostream>

using namespace std;

int n, m, k;
int mineral[1010][1010];
int now[1010][1010];
int cnt;

void floodFill(int i, int j, int d)
{
	cnt++;
	now[i][j] = 0;
	if (now[i - 1][j] != 0 && now[i - 1][j] <= d) floodFill(i - 1, j, d);
	if (now[i + 1][j] != 0 && now[i + 1][j] <= d) floodFill(i + 1, j, d);
	if (now[i][j - 1] != 0 && now[i][j - 1] <= d) floodFill(i, j - 1, d);
	if (now[i][j + 1] != 0 && now[i][j + 1] <= d) floodFill(i, j + 1, d);
}

bool para(int d)
{
	int i, j;
	for (i = 0; i <= n + 1; i++) {
		for (j = 0; j <= m + 1; j++) {
			if (i == 0 || j == 0 || j == m + 1) now[i][j] = 0;
			else if (i == n + 1) now[i][j] = 2147483647;
			else now[i][j] = mineral[i][j];
		}
	}

	cnt = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (now[i][j] == 0 || now[i][j] > d) continue;

			if (now[i - 1][j] == 0 || now[i + 1][j] == 0 || now[i][j - 1] == 0 || now[i][j + 1] == 0) {
				floodFill(i, j, d);
			}
		}
	}

	if (cnt >= k) return true;
	return false;
}

int main()
{
	int i, j;
	int s = 1, e = 0;

	cin >> n >> m >> k;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> mineral[i][j];
			if (e < mineral[i][j]) e = mineral[i][j];
		}
	}

	int mi = (s + e) / 2;

	while (s < e) {
		if (para(mi)) {
			e = mi - 1;
			mi = (s + e) / 2;
		}
		else {
			s = mi + 1;
			mi = (s + e) / 2;
		}
	}

	if (para(mi)) cout << mi;
	else cout << mi + 1;

	return 0;
}