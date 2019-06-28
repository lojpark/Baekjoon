#include <iostream>

using namespace std;

int n;
int d[20][20];

struct Data {
	int t;
	int p;
}a[20];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t >> a[i].p;
		d[i][i + a[i].t - 1] = a[i].p;
	}

	for (int j = 1; j <= n; j++) {
		for (int i = j; i >= 1; i--) {
			for (int k = i; k < j; k++) {
				if (d[i][j] < d[i][k] + d[k + 1][j]) {
					d[i][j] = d[i][k] + d[k + 1][j];
				}
			}
		}
	}

	cout << d[1][n];

	return 0;
}