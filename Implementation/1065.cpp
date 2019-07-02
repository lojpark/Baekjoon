#include <iostream>

using namespace std;

bool is_hansu(int number)
{
	int prev = number % 10, d = 0;
	number /= 10;
	d = prev - number % 10;

	while (number > 0) {
		if (prev - number % 10 != d)
			return false;
		prev = number % 10;
		number /= 10;
	}
	return true;
}

int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (is_hansu(i))
			count++;
	}

	cout << count;

	return 0;
}