#include <iostream>

using namespace std;

int main()
{
	int a[10];
	for (int i = 1; i <= 8; i++)
		cin >> a[i];

	if (a[2] - a[1] > 0) {
		for (int i = 3; i <= 8; i++) {
			if (a[i] - a[i - 1] < 0) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}
	else {
		for (int i = 3; i <= 8; i++) {
			if (a[i] - a[i - 1] > 0) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}

	return 0;
}