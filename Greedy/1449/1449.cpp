#include <iostream>
#include <algorithm>

using namespace std;

int n, l;
int a[1010];

int main()
{
	int i;

	cin >> n >> l;

	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	int count = 1;
	double next = a[1] - 0.5 + l;

	for (i = 2; i <= n; i++) {
		if (a[i] > next) {
			count++;
			next = a[i] - 0.5 + l;
		}
	}

	cout << count;

	return 0;
}