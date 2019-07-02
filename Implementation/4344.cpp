#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int c;
	cin >> c;
	for (; c >= 1; c--) {
		int n;
		int a[1010], count = 0;
		double sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] > (sum / n))
				count++;
		}
		printf("%.3lf%%\n", count / (double)n * 100);
	}

	return 0;
}