/*
d[i][1][0] = i��° �Ͽ� �丶�� �ҽ��� �԰� i - 1��° �Ͽ��� �丶�� �ҽ��� �ȸ��� ����� ��
d[i][1][1] = i��° �Ͽ� �丶�� �ҽ��� �԰� i - 1��° �Ͽ��� �丶�� �ҽ��� ���� ����� ��
d[i][2][0] = i��° �Ͽ� ũ�� �ҽ��� �԰� i - 1��° �Ͽ��� ũ�� �ҽ��� �ȸ��� ����� ��
d[i][2][1] = i��° �Ͽ� ũ�� �ҽ��� �԰� i - 1��° �Ͽ��� ũ�� �ҽ��� ���� ����� ��
d[i][3][0] = i��° �Ͽ� ���� �ҽ��� �԰� i - 1��° �Ͽ��� ���� �ҽ��� �ȸ��� ����� ��
d[i][3][1] = i��° �Ͽ� ���� �ҽ��� �԰� i - 1��° �Ͽ��� ���� �ҽ��� ���� ����� ��
*/
#include <iostream>

using namespace std;

int n, k;
int decide[110];
int d[110][4][2];

int main()
{
	cin >> n >> k;

	int input1, input2;
	for (int i = 1; i <= k; i++) {
		cin >> input1 >> input2;
		decide[input1] = input2;
	}

	if (decide[1] == 0)
		d[1][1][0] = d[1][2][0] = d[1][3][0] = 1;
	else
		d[1][decide[1]][0] = 1;
	for (int i = 2; i <= n; i++) {
		if (decide[i] == 1 || decide[i] == 0) {
			d[i][1][0] = (d[i - 1][2][0] + d[i - 1][2][1] + d[i - 1][3][0] + d[i - 1][3][1]) % 10000;
			d[i][1][1] = d[i - 1][1][0];
		}

		if (decide[i] == 2 || decide[i] == 0) {
			d[i][2][0] = (d[i - 1][1][0] + d[i - 1][1][1] + d[i - 1][3][0] + d[i - 1][3][1]) % 10000;
			d[i][2][1] = d[i - 1][2][0];
		}

		if (decide[i] == 3 || decide[i] == 0) {
			d[i][3][0] = (d[i - 1][1][0] + d[i - 1][1][1] + d[i - 1][2][0] + d[i - 1][2][1]) % 10000;
			d[i][3][1] = d[i - 1][3][0];
		}
	}

	cout << (d[n][1][0] + d[n][1][1] + d[n][2][0] + d[n][2][1] + d[n][3][0] + d[n][3][1]) % 10000;
	return 0;
}