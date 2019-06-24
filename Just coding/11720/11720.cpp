#include <iostream>

using namespace std;

int main()
{
	int n;
	char a[110];

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int answer = 0;
	for (int i = 1; i <= n; i++)
		answer += a[i] - '0';

	cout << answer;

	return 0;
}