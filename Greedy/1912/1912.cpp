/*
Greedy
*/
#include <iostream>

using namespace std;

int n;
int a[100010] = {0};

int main()
{
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	int max = -2147483647;
	int l = 1, r = 1, value = 0;

	while (r <= n) {
		if (a[r] - a[r - 1] > a[r] - a[l - 1]) {
			l = r;
		}
		value = a[r] - a[l - 1];
		r++;

		if (max < value) max = value;
	}

	cout << max << endl;

	return 0;
}