/*
memo[i] = n을 i로 만드는 데 필요한 최소 횟수
*/
#include <iostream>

using namespace std;

int memo[1000010];

int main()
{
	int num;

	cin >> num;

	memo[num] = 1;

	for (int i = num; i >= 1; i--) {
		if (!memo[i]) continue;
		if (i % 2 == 0 && (memo[i / 2] == 0 || memo[i / 2] > memo[i] + 1)) memo[i / 2] = memo[i] + 1;
		if (i % 3 == 0 && (memo[i / 3] == 0 || memo[i / 3] > memo[i] + 1)) memo[i / 3] = memo[i] + 1;
		if (memo[i - 1] == 0 || memo[i - 1] > memo[i] + 1) memo[i - 1] = memo[i] + 1;
	}

	cout << memo[1] - 1;

	return 0;
}