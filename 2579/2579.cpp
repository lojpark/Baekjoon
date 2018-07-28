/*
d[0][i] = 바로 직전에 2칸 뛰어 i번째 계단을 밟았을 때의 최댓값
d[1][i] = 바로 직전에 1칸 뛰어 i번째 계단을 밟았을 때의 최댓값
*/
#include <iostream>

using namespace std;

int n;
int a[310];
int d[3][310];

int main()
{
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[0][1] = a[1];
	d[0][2] = a[2];
	for (i = 2; i <= n; i++) {
		d[0][i] = d[0][i - 2];
		if (d[0][i] < d[1][i - 2]) d[0][i] = d[1][i - 2];
		d[0][i] += a[i];

		d[1][i] = d[0][i - 1] + a[i];
	}

	if (d[0][n] > d[1][n]) cout << d[0][n];
	else cout << d[1][n];

	return 0;
}