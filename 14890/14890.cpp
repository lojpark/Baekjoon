#include <iostream>
#include <vector>

using namespace std;

int n, l;
int a[110][110];
bool v[110][110];

int main()
{
	int i, j, k;
	cin >> n >> l;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	int answer = 0;
	// Left to Right
	for (i = 1; i <= n; i++) {
		for (j = 1; j < n; j++) {
			if (a[i][j] == a[i][j + 1])
				continue;

			// Down slope
			if (a[i][j] == a[i][j + 1] + 1) {
				for (k = j + 1; k <= j + l; k++) {
					if (k > n) {
						k = -1;
						break;
					}
					if (a[i][k] + 1 == a[i][j] && !v[i][k])
						v[i][k] = true;
					else {
						k = -1;
						break;
					}
				}
				if (k == -1) {
					j = -1;
					break;
				}
				continue;
			}

			// Up slope
			if (a[i][j] == a[i][j + 1] - 1) {
				for (k = j - l + 1; k <= j; k++) {
					if (k < 1) {
						k = -1;
						break;
					}
					if (a[i][k] + 1 == a[i][j + 1] && !v[i][k])
						v[i][k] = true;
					else {
						k = -1;
						break;
					}
				}
				if (k == -1) {
					j = -1;
					break;
				}
				continue;
			}

			j = -1;
			break;
		}
		if (j != -1)
			answer++;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			v[i][j] = false;
	}

	// Up to Down
	for (j = 1; j <= n; j++) {
		for (i = 1; i < n; i++) {
			if (a[i][j] == a[i + 1][j])
				continue;

			// Down slope
			if (a[i][j] == a[i + 1][j] + 1) {
				for (k = i + 1; k <= i + l; k++) {
					if (k > n) {
						k = -1;
						break;
					}
					if (a[k][j] + 1 == a[i][j] && !v[k][j])
						v[k][j] = true;
					else {
						k = -1;
						break;
					}
				}
				if (k == -1) {
					i = -1;
					break;
				}
				continue;
			}

			// Up slope
			if (a[i][j] == a[i + 1][j] - 1) {
				for (k = i - l + 1; k <= i; k++) {
					if (k < 1) {
						k = -1;
						break;
					}
					if (a[k][j] + 1 == a[i + 1][j] && !v[k][j])
						v[k][j] = true;
					else {
						k = -1;
						break;
					}
				}
				if (k == -1) {
					i = -1;
					break;
				}
				continue;
			}

			i = -1;
			break;
		}
		if (i != -1)
			answer++;
	}
	cout << answer;
}