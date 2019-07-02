#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	for (int i = 1000; i >= 0; i--) {
		for (int j = 1667; j >= 0; j--) {
			if (i * 5 + j * 3 == n) {
				cout << i + j;
				return 0;
			}
		}
	}
	cout << "-1";

	return 0;
}