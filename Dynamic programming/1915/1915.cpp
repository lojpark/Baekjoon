/*
d[i][j] = (i, j)�� ������ �Ʒ� ���������� �ϴ� ���簢���� �ִ� ũ��
*/
#include <iostream>

using namespace std;

int n, m;
char a[1010][1010];
int d[1010][1010];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> (a[i] + 1);
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '0') {
				d[i][j] = 0;
				continue;
			}

			d[i][j] = d[i - 1][j];
			if (d[i][j] > d[i][j - 1]) d[i][j] = d[i][j - 1];
			if (d[i][j] > d[i - 1][j - 1]) d[i][j] = d[i - 1][j - 1];
			d[i][j]++;

			if (max < d[i][j]) max = d[i][j];
		}
	}

	cout << max * max;
}