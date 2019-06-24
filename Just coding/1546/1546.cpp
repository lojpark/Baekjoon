#include <iostream>

using namespace std;

int main()
{
	int n;
	double a[1010], max = 1, sum = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (max < a[i])
			max = a[i];
	}

	for (int i = 1; i <= n; i++)
		sum += a[i] / max * 100;

	cout << sum / n;

	return 0;
}