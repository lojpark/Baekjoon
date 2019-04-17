#include <iostream>

using namespace std;

int n;
long long int a[1000010];
long long int b, c;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	long long int answer = 0;
	for (int i = 1; i <= n; i++) {
		a[i] -= b;
		answer++;

		if (a[i] <= 0)
			continue;

		if (a[i] % c == 0)
			answer += (int)(a[i] / c);
		else
			answer += (int)(a[i] / c) + 1;
	}

	cout << answer;
}