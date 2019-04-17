/*
d[i] = i만큼의 비용을 사용해서 비활성화 시킬 수 있는 메모리의 최댓값 (knapsack)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[10010];

struct Data
{
	int m;
	int c;
}a[110];

bool cmp(Data arg1, Data arg2)
{
	return arg1.c < arg2.c;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].m;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
	}

	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		for (int j = 10000; j >= 0; j--) {
			if (d[j] > 0) {
				if (d[j + a[i].c] < d[j] + a[i].m) {
					d[j + a[i].c] = d[j] + a[i].m;
				}
			}
		}
		if (d[a[i].c] < a[i].m) {
			d[a[i].c] = a[i].m;
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (d[i] >= m) {
			cout << i;
			break;
		}
	}

	return 0;
}