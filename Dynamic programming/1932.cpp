#include <iostream>

using namespace std;

int n;
int a[510][510];

int max(int t, int u)
{
	if (t > u)
		return t;
	return u;
}

int main()
{
	int answer = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
			answer = max(answer, a[i][j]);
		}
	}
	cout << answer;

	return 0;
}