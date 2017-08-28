/*
Dynamic programming
d[k][i][j] : 1~i까지, j~n까지 문자열을 전부 썼을 때의 값
			 1~i까지, j~n까지 문자열을 전부 쓰지 못하면 0
			 (쉽게 계산하기 위해 i행은 rdrug 사용)
			 마지막으로 사용한 게 drug면 k == 0, rdrug면 k == 1
*/
#include <iostream>
#include <string.h>

using namespace std;

char drug[1510];
char rdrug[1510];
int d[2][1510][1510] = {0};

inline int bigger(int numA, int numB) {
	return (numA > numB ? numA : numB);
}

char prevDrug(char now) {
	if (now == 'B') return 'D';
	else if (now == 'L') return 'B';
	return 'L';
}

int main()
{
	int i, j;
	int n, max = 0;

	cin >> n >> drug;

	n *= 3;

	for (i = n; i >= 1; i--) {
		drug[i] = drug[i-1];
		rdrug[n + 1 - i] = drug[i];
	}
	drug[0] = rdrug[0] = '0';
	drug[n + 1] = rdrug[n + 1] = '\0';

	d[0][0][0] = d[1][0][0] = 0;
	if (drug[1] == 'B') {
		d[0][0][1] = 1;
		for (i = 2; i <= n; i++) {
			if (drug[i - 1] == prevDrug(drug[i])) {
				d[0][0][i] = d[0][0][i - 1] + 1;
			}
			else break;
		}
	}

	if (rdrug[1] == 'B') {
		d[1][1][0] = 1;
		for (i = 2; i <= n; i++) {
			if (rdrug[i - 1] == prevDrug(rdrug[i])) {
				d[1][i][0] = d[1][i - 1][0] + 1;
			}
			else break;
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n - i; j++) {
			if (drug[j] == prevDrug(rdrug[i])) {
				if (d[1][i][j] < d[0][i - 1][j] + 1 && d[0][i - 1][j] != 0) {
					d[1][i][j] = d[0][i - 1][j] + 1;
				}
			}
			if (drug[j - 1] == prevDrug(drug[j])) {
				if (d[0][i][j] < d[0][i][j - 1] + 1 && d[0][i][j - 1] != 0) {
					d[0][i][j] = d[0][i][j - 1] + 1;
				}
			}
			if (rdrug[i - 1] == prevDrug(rdrug[i])) {
				if (d[1][i][j] < d[1][i - 1][j] + 1 && d[1][i - 1][j] != 0) {
					d[1][i][j] = d[1][i - 1][j] + 1;
				}
			}
			if (rdrug[i] == prevDrug(drug[j])) {
				if (d[0][i][j] < d[1][i][j - 1] + 1 && d[1][i][j - 1] != 0) {
					d[0][i][j] = d[1][i][j - 1] + 1;
				}
			}
			
			if (drug[i] == prevDrug(rdrug[j])) {
				if (d[1][j][i] < d[0][j - 1][i] + 1 && d[0][j - 1][i] != 0) {
					d[1][j][i] = d[0][j - 1][i] + 1;
				}
			}
			if (rdrug[j - 1] == prevDrug(rdrug[j])) {
				if (d[1][j][i] < d[1][j - 1][i] + 1 && d[1][j - 1][i] != 0) {
					d[1][j][i] = d[1][j - 1][i] + 1;
				}
			}
			if (drug[i - 1] == prevDrug(drug[i])) {
				if (d[0][j][i] < d[0][j][i - 1] + 1 && d[0][j][i - 1] != 0) {
					d[0][j][i] = d[0][j][i - 1] + 1;
				}
			}
			if (rdrug[j] == prevDrug(drug[i])) {
				if (d[0][j][i] < d[1][j][i - 1] + 1 && d[1][j][i - 1] != 0) {
					d[0][j][i] = d[1][j][i - 1] + 1;
				}
			}
		}
	}

	max = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (max < d[0][i][j]) {
				max = d[0][i][j];
			}
			if (max < d[1][i][j]) {
				max = d[1][i][j];
			}
	//		cout << "(" << d[0][i][j] << ", " << d[1][i][j] << ") ";
		}
	//	cout << endl;
	}

	cout << max << endl;

	return 0;
}
