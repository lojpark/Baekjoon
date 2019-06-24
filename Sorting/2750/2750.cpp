#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[1010];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)
		cout << a[i] << endl;

	return 0;
}