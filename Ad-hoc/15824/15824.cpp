#include <iostream>
#include <algorithm>

int n;
long long a[300010];
long long powerOfTwo[300010];

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	powerOfTwo[0] = 1;
	for (int i = 1; i <= n; i++) {
		powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % 1000000007;
	}

	std::sort(a + 1, a + 1 + n);

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = (sum + (a[i] * (powerOfTwo[i - 1] - powerOfTwo[n - i])) % 1000000007 + 1000000007) % 1000000007;
	}

	std::cout << sum;

	return 0;
}