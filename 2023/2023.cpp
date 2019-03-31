#include <iostream>
#include <math.h>

using namespace std;

int n;

bool is_prime(int number)
{
	int limit = (int)sqrt(number);
	for (int i = 2; i <= limit; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void dfs(int number, int len)
{
	if (len >= n) {
		cout << number << endl;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (is_prime(number * 10 + i))
			dfs(number * 10 + i, len + 1); 
	}
}

int main()
{
	cin >> n;
	for (int i = 2; i <= 9; i++) {
		if (is_prime(i))
			dfs(i, 1);
	}
	return 0;
}