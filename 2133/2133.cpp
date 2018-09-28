/*
d[i] = 3xN 크기의 타일을 채우는 총 경우의 수
*/
#include <iostream>

using namespace std;

int n;
int d[31];

int main()
{
	cin >> n;

	d[1] = 2;
	d[2] = 3;

	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			d[i] = d[i - 2] * 3;
			for (int j = i - 3; j >= 1; j -= 2) {
				d[i] += d[j];
			}
		}
		else {
			d[i] = d[i - 1] * 2;
		}
	}

	if (n % 2 == 0)
		cout << d[n];
	else
		cout << "0";

	return 0;
}