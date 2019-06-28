#include <iostream>
#include <string.h>

using namespace std;

long long k, n;
long long memo[128][64];

long long dfs(int height, int time)
{
	if (height == 0) return 0;
	if (time == 0) return 1;

	if (memo[height][time] != -1) return memo[height][time];

	memo[height][time] = dfs(height - 1, time - 1) + dfs(height + 1, time - 1);
	return memo[height][time];
}

int main()
{
	cin >> k >> n;

	memset(memo, -1, sizeof(memo));

	cout << dfs(k, n);

	return 0;
}