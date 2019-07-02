#include <iostream>

using namespace std;

int a[10010];
int d[10010][2];

int max(int t, int u)
{
	if (t > u)
		return t;
	return u;
}

int main()
{
	int n;
	int answer = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			d[i][0] = a[i];
			d[i][1] = 0;
		}
		else {
			d[i][0] = max(max(d[i - 2][0], d[i - 2][1]) + a[i], max(d[i - 1][0], d[i - 1][1]));
			d[i][1] = d[i - 1][0] + a[i];
		}
		answer = max(answer, d[i][0]);
		answer = max(answer, d[i][1]);
	}

	cout << answer;

	return 0;
}