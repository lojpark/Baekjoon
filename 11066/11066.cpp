/*
Dynamic programming
d[k][i][j] : i~j까지의 파일을 합쳤을 때의 최소 값
			 k == 0 : 전부 더한 값
			 k == 1 : 최종 계산을 제외한 값
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[510];
int d[2][510][510];

int main()
{
	int t;
	int i, j, k;

	cin >> t;
	for (; t >= 1; t--) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				d[0][i][j] = d[1][i][j] = 0;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 1; ; j++) {
				if (j + i > n) break;
				if (i == 0) {
					d[0][j][j + i] = a[j];
					d[1][j][j + i] = 0;
				}
				else if (i == 1) {
					d[0][j][j + i] = d[0][j][j + i - 1] + d[0][j + 1][j + i];
					d[1][j][j + i] = d[0][j][j + i - 1] + d[0][j + 1][j + i];
				}
				else {
					int min = 2147483647, tmp = 0, ind = 0;
					for (k = 0; k < i; k++) {
						tmp = d[0][j][j + i - (i - k)] + d[1][j][j + i - (i - k)] + d[0][j + (k + 1)][j + i] + d[1][j + (k + 1)][j + i];
						if (min > tmp) {
							min = tmp;
							if (d[1][j][j + i - (i - k)] == 0) tmp = d[0][j][j + i - (i - k)];
							else tmp = d[1][j][j + i - (i - k)];
							ind = tmp;
							if (d[1][j + (k + 1)][j + i] == 0) tmp = d[0][j + (k + 1)][j + i];
							else tmp = d[1][j + (k + 1)][j + i];
							ind += tmp;
						}
						else if (min == tmp) {
							if (d[1][j][j + i - (i - k)] == 0) tmp = d[0][j][j + i - (i - k)];
							else tmp = d[1][j][j + i - (i - k)];
							if (d[1][j + (k + 1)][j + i] == 0) tmp += d[0][j + (k + 1)][j + i];
							else tmp += d[1][j + (k + 1)][j + i];
							if (ind > tmp) {
								ind = tmp;
							}
						}
					}
					d[0][j][j + i] = min;
					d[1][j][j + i] = ind;
				}
			}
		}

		cout << d[0][1][n] << endl;
	}
	return 0;
}