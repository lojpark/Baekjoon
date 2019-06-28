/*
d[i] = 1, 2, 3을 이용해 i를 만드는 경우의 수
*/
#include <iostream>

using namespace std;

int n, t;
int d[20];

int main()
{
	int i;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	cin >> t;

	for (; t >= 1; t--) {
		cin >> n;
		cout << d[n] << endl;
	}

	return 0;
}