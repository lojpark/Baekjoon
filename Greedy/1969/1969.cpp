#include <iostream>

using namespace std;

int n, m;
char str[1010][51];
char answer[51];

int main()
{
	int i, j;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> str[i];
	}

	int sum = 0;
	for (j = 0; j < m; j++) {
		int a = 0, g = 0, c = 0, t = 0;
		for (i = 1; i <= n; i++) {
			switch (str[i][j]) {
			case 'A':
				a++;
				break;
			case 'G':
				g++;
				break;
			case 'C':
				c++;
				break;
			case 'T':
				t++;
				break;
			}
		}
		if (a >= c && a >= g && a >= t) {
			answer[j] = 'A';
			sum += c + g + t;
		}
		else if (c >= a && c >= g && c >= t) {
			answer[j] = 'C';
			sum += a + g + t;
		}
		else if (g >= c && g >= a && g >= t) {
			answer[j] = 'G';
			sum += a + c + t;
		}
		else {
			answer[j] = 'T';
			sum += a + c + g;
		}
	}
	answer[j] = '\0';

	cout << answer << endl << sum;

	return 0;
}