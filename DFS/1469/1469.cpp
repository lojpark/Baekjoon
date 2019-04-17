#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[11];
bool v[11];
int s[50];

bool dfs(int index, int count)
{
	if (count == n) {
		for (int i = 1; i <= n * 2; i++) {
			cout << s[i] << " ";
		}
		return true;
	}

	if (s[index] != -1) {
		return dfs(index + 1, count);
	}

	for (int i = 1; i <= n; i++) {
		if (!v[i] && index + x[i] + 1 <= n * 2 && s[index + x[i] + 1] == -1) {
			v[i] = true;
			s[index] = s[index + x[i] + 1] = x[i];

			if (dfs(index + 1, count + 1))
				return true;

			v[i] = false;
			s[index] = s[index + x[i] + 1] = -1;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n * 2; i++)
		s[i] = -1;

	sort(x + 1, x + 1 + n);

	if (!dfs(1, 0))
		cout << "-1";

	return 0;
}