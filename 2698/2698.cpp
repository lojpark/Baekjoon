/*
d[i][j][0] = j번째 비트가 0일 때, j개의 비트 중 i개의 비트가 인접한 경우의 수
d[i][j][1] = j번째 비트가 1일 때, j개의 비트 중 i개의 비트가 인접한 경우의 수
*/
#include <iostream>

using namespace std;

int n, k;
long long d[110][110][2];

int main()
{
	d[0][1][0] = d[0][1][1] = 1;

	for (int i = 0; i <= 100; i++) {
		for (int j = 2; j <= 100; j++) {
			d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][1];
			if (i == 0)
				d[i][j][1] = d[i][j - 1][0];
			else
				d[i][j][1] = d[i][j - 1][0] + d[i - 1][j - 1][1];
		}
	}

	int t;

	cin >> t;
	for (; t >= 1; t--) {
		cin >> n >> k;
		cout << d[k][n][0] + d[k][n][1] << endl;
	}

	return 0;
}