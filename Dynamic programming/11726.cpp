/*
d[i] = 1x2 Ÿ���� �̿��� 2xi Ÿ���� ä��� ����� ��
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