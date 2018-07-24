#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct Data {
	int solve;
	int p;
}a[100];

bool cmp(Data arg1, Data arg2)
{
	if (arg1.solve == arg2.solve) {
		return arg1.p < arg2.p;
	}
	return arg1.solve > arg2.solve;
}

int main()
{
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i].solve >> a[i].p;
	}

	sort(a + 1, a + n + 1, cmp);

	int count = 0;
	for (i = 6; i <= n; i++) {
		if (a[i].solve == a[5].solve) {
			count++;
		}
	}

	cout << count;

	return 0;
}