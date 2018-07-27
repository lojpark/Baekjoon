#include <iostream>

using namespace std;

int n, k;
int a[1000010];

bool para(int d)
{
	int i;
	int cnt = 0;

	for (i = 1; i <= d; i++) {
		if (a[i] == 1) cnt++;
		if (cnt >= k) return true;
	}
	for (i = d + 1; i <= n; i++) {
		if (a[i] == 1) cnt++;
		if (a[i - d] == 1) cnt--;
		if (cnt >= k) return true;
	}

	return false;
}

int main()
{
	int i;

	cin >> n >> k;

	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int s = 1, e = n;
	int m = (s + e) / 2;
	int answer = n + 1;

	while (s <= e) {
		if (para(m)) {
			if (answer > m) answer = m;
			e = m - 1;
			m = (s + e) / 2;
		}
		else {
			s = m + 1;
			m = (s + e) / 2;
		}
	}

	if (answer == n + 1) cout << -1;
	else cout << answer;
}