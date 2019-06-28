#include <iostream>
#include <string>

using namespace std;

int a[1010][3];
int d[1010][3];

int min(int t, int u)
{
	if (t < u)
		return t;
	return u;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];

	for (int i = 1; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}

	cout << min(d[n][0], min(d[n][1], d[n][2]));

	return 0;
}