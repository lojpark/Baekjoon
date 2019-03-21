#include <iostream>

using namespace std;

int a[1010][1010];
int d[1010][1010];

inline int min(int num1, int num2, int num3) {
	int min_num = num1;
	if (min_num > num2)
		min_num = num2;
	if (min_num > num3)
		min_num = num3;
	return min_num;
}

int main()
{
	int n, m;
	int max = 0;

	while (true) {
		max = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				d[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 0)
					d[i][j] = 0;
				else
					d[i][j] = min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1;
				if (max < d[i][j])
					max = d[i][j];
			}
		}

		cout << max << endl;
	}
	return 0;
}