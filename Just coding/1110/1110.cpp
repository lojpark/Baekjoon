#include <iostream>

using namespace std;

int main()
{
	int n, new_n, count = 0;
	bool v[110] = { 0 };

	cin >> n;

	while (true) {
		new_n = ((int)(n / 10) + n % 10) % 10;
		new_n += (n % 10) * 10;
		if (v[n = new_n])
			break;
		v[n] = true;
		count++;
	}

	cout << count;

	return 0;
}