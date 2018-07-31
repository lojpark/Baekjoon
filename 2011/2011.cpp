/*
d[i] = i번째 암호까지의 총 해석 가능한 경우의 수
*/
#include <iostream>
#include <string.h>

using namespace std;

int n;
char code[5010];
long long d[5010];

int main()
{
	cin >> (code + 1);

	d[0] = d[1] = 1;
	for (int i = 2; i <= (n = strlen(code + 1)); i++) {
		if (code[i] == '0' && code[i - 1] != '1' && code[i - 1] != '2') {
			d[i] = 0;
		}
		if ((code[i - 1] == '1' || (code[i - 1] == '2' && code[i] <= '6')) && code[i] != '0') {
			d[i] = (d[i - 1] + d[i - 2]) % 1000000;
		}
		else if (code[i] == '0') {
			d[i] = d[i - 2];
		}
		else {
			d[i] = d[i - 1];
		}
	}

	if (code[1] == '0') cout << "0";
	else cout << d[n];

	return 0;
}