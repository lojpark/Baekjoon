#include <iostream>

using namespace std;

int a[10010];

int main()
{
	for (int i = 1; i <= 10000; i++) {
		int n = i, dn = i;
		while (n > 0) {
			dn += n % 10;
			n /= 10;
		}
		if (dn <= 10000)
			a[dn] = i;
	}
	for (int i = 1; i <= 10000; i++) {
		if (a[i] == 0)
			cout << i << endl;
	}

	return 0;
}