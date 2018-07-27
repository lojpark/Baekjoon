#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
struct Data {
	int d;
	int t;
}a[1000100];

bool cmp(Data arg1, Data arg2)
{
	return arg1.t > arg2.t;
}

int main()
{
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i].d >> a[i].t;
	}

	sort(a + 1, a + 1 + n, cmp);

	int date = 1000000001;
	for (i = 1; i <= n; i++) {
		if (a[i].t <= date) {
			date = a[i].t - a[i].d;
		}
		else {
			date -= a[i].d;
		}
	}

	cout << date;

	return 0;
}