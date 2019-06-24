#include <iostream>

using namespace std;

int main()
{
	int a, b, c, sum = 0;
	int count[10] = { 0 };

	cin >> a >> b >> c;
	sum = a * b * c;

	while (true) {
		count[sum % 10]++;
		sum /= 10;
		if (sum == 0)
			break;
	}

	for (int i = 0; i < 10; i++)
		cout << count[i] << endl;

	return 0;
}