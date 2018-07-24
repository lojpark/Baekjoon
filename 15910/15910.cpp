#include <iostream>
#include <string.h>

using namespace std;

int n;
char str[100010];
int d[7][100010];

int main()
{
	cin >> str;

	n = strlen(str);

	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 100000000;
		}
	}

	if (str[0] == 'B') d[1][0] = 0;
	else d[1][0] = 1;

	for (int i = 1; i < n; i++) {
		int min = 2147483647;
		// State 1
		if (d[1][i - 1] < d[6][i - 1]) d[1][i] = d[1][i - 1];
		else d[1][i] = d[6][i - 1];
		if (str[i] != 'B') d[1][i]++;

		// State 2
		d[2][i] = d[1][i - 1];
		if (str[i] != 'A') d[2][i]++;

		// State 3
		d[3][i] = d[2][i - 1];
		if (str[i] != 'N') d[3][i]++;

		// State 4
		d[4][i] = d[3][i - 1];
		if (str[i] != 'A') d[4][i]++;

		// State 5
		if (d[4][i - 1] < d[6][i - 1]) d[5][i] = d[4][i - 1];
		else d[5][i] = d[6][i - 1];
		if (str[i] != 'N') d[5][i]++;

		// State 6
		d[6][i] = d[5][i - 1];
		if (str[i] != 'A') d[6][i]++;
	}

	cout << d[6][n - 1];

	return 0;
}