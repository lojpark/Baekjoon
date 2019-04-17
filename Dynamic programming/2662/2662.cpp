/*
d[i][j] = i만원을 이용해 1 ~ j까지의 기업에 투자할 때의 최댓값
*/
#include <iostream>

using namespace std;

int n, m;
int a[310][21];
int d[310][21];
int path[310][21];
int answer[21], an;

int main()
{
	int i, j, k;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (i = 1; i <= n; i++) d[i][1] = a[i][1];

	for (j = 2; j <= m; j++) {
		for (i = 1; i <= n; i++) {
			for (k = 0; k <= i; k++) {
				if (d[i][j] < d[k][j - 1] + a[i - k][j]) {
					d[i][j] = d[k][j - 1] + a[i - k][j];
					path[i][j] = k;
				}
			}

		}
	}

	int an = 0;
	int p = path[n][m];
	answer[++an] = n - p;
	for (j = m - 1; j > 1; j--) {
		answer[++an] = p - path[p][j];
		p = path[p][j];
	}
	answer[++an] = p;

	cout << d[n][m] << endl;
	for (i = an; i >= 1; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}