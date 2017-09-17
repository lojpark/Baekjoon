/*
Just coding
*/
#include <iostream>
#include <algorithm>

int n;
int a[1010];

bool cmp(int q, int qq)
{
	return q > qq;
}

int main()
{
	int i;
	std::cin >> n;
	for (i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a + 1, a + 1 + n, cmp);

	for (i = n; i >= 1; i--) {
		if (a[i] >= i) {
			std::cout << i;
			return 0;
		}
	}	

	std::cout << "0";
	return 0;
}