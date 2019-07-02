#include <iostream>

using namespace std;

int gcd(int t, int u)
{
	if (u == 0)
		return t;
	return gcd(u, t % u);
}

int main()
{
	int a, b;

	cin >> a >> b;
	cout << gcd(a, b) << endl << a * b / gcd(a, b);

	return 0;
}