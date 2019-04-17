#include <iostream>

using namespace std;

int n, m;
char a[51][51] = { 0 };

int count_new(int sx, int sy, bool flag)
{
	int count = 0;
	for (int i = sy; i < sy + 8; i++) {
		for (int j = sx; j < sx + 8; j++) {
			if (!flag && a[i][j] == 'W')
				count++;
			else if (flag && a[i][j] == 'B')
				count++;
			flag = !flag;
		}
		flag = !flag;
	}
	return count;
}

int main()
{

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int min = 2147483647, temp;
	for (int i = 1; i <= n - 7; i++) {
		for (int j = 1; j <= m - 7; j++) {
			temp = count_new(j, i, false);
			if (min > temp)
				min = temp;
			temp = count_new(j, i, true);
			if (min > temp)
				min = temp;
		}
	}

	cout << min;

	return 0;
}