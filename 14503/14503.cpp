#include <iostream>

using namespace std;

int n, m;
int r, c, d;
int a[60][60];
bool v[60][60];

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;

	r++;
	c++;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			a[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int cas = 1, answer = 0;
	while (true) {
		if (cas == 1) {
			v[r][c] = true;
			answer++;
		}

		cas = 0;

		if ((v[r - 1][c] || a[r - 1][c] == 1) && (v[r + 1][c] || a[r + 1][c] == 1) && (v[r][c - 1] || a[r][c - 1] == 1) && (v[r][c + 1] || a[r][c + 1] == 1)) {
			switch (d) {
			case 0:
				r++;
				break;
			case 1:
				c--;
				break;
			case 2:
				r--;
				break;
			case 3:
				c++;
				break;
			}
			if (a[r][c] == 1)
				break;
			cas = 2;
			continue;
		}

		switch (d) {
		case 0:
			d = 3;
			if (!v[r][c - 1] && a[r][c - 1] == 0) {
				c--;
				cas = 1;
			}
			else {
				cas = 2;
			}
			break;
		case 1:
			d = 0;
			if (!v[r - 1][c] && a[r - 1][c] == 0) {
				r--;
				cas = 1;
			}
			else {
				cas = 2;
			}
			break;
		case 2:
			d = 1;
			if (!v[r][c + 1] && a[r][c + 1] == 0) {
				c++;
				cas = 1;
			}
			else {
				cas = 2;
			}
			break;
		case 3:
			d = 2;
			if (!v[r + 1][c] && a[r + 1][c] == 0) {
				r++;
				cas = 1;
			}
			else {
				cas = 2;
			}
			break;
		default:
			break;
		}
	}
	cout << answer;
}