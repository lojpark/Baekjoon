#include <iostream>

using namespace std;

bool is_prime(int number)
{
	if (number == 1)
		return false;
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		if (is_prime(input))
			count++;
	}
	cout << count;

	return 0;
}