#include <iostream>

using namespace std;

int main()
{
	int n, d, answer;

	cin >> n;

	d = 0;
	answer = 1;
	for (int i = 1; i <= n; i += d) {
		if (n <= i)
			break;
		answer++;
		d += 6;
	}

	cout << answer;
	return 0;
}