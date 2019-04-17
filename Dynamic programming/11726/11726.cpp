/*
d[i] = 1x2 타일을 이용해 2xi 타일을 채우는 경우의 수
*/
#include <iostream>

using namespace std;

int n;
int d[1010];

int main()
{
	int i;
	cin >> n;

	d[1] = 1;
	d[2] = 2;
	for (i = 3; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % 10007;

	cout << d[n];

	return 0;
}