#include <iostream>

using namespace std;

int d[41][2];

int main()
{
	d[0][1] = d[1][0] = 0;
	d[0][0] = d[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		d[i][0] = d[i - 1][1];
		d[i][1] = d[i - 1][0] + d[i - 1][1];
	}

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		cout << d[input][0] << " " << d[input][1] << endl;
	}

	return 0;
}