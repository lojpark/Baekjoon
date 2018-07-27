#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
struct Data {
	int s;
	int e;
}a[5010];

bool cmp(Data arg1, Data arg2)
{
	return arg1.s < arg2.s;
}

int main()
{
	int i;

	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> a[i].s >> a[i].e;
	}

	sort(a + 1, a + 1 + m, cmp);

	int cnt = 0;

	a[0].s = a[0].e = 0;
	for (i = 1; i <= m; i++) {
		if (a[i].s > a[i - 1].e) {
			cnt += a[i].s - a[i - 1].e;
		}
		else {
			if (a[i].e < a[i - 1].e) a[i].e = a[i - 1].e;
		}
	}
	cnt += n - a[m].e;

	cout << cnt;

	return 0;
}