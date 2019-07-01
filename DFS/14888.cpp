#include <iostream>

using namespace std;

int n;
int number[20];
int remain[5];
int calc[20];
int min_answer, max_answer;

int calculate()
{
	int result = number[1];
	for (int i = 1; i < n; i++) {
		switch (calc[i]) {
		case 1:
			result += number[i + 1];
			break;
		case 2:
			result -= number[i + 1];
			break;
		case 3:
			result *= number[i + 1];
			break;
		case 4:
			result /= number[i + 1];
			break;
		default:
			break;
		}
	}
	return result;
}

void dfs(int index)
{
	if (index >= n) {
		int result = calculate();
		if (min_answer > result)
			min_answer = result;
		if (max_answer < result)
			max_answer = result;
	}
	for (int i = 1; i <= 4; i++) {
		if (remain[i] > 0) {
			calc[index] = i;
			remain[i]--;
			dfs(index + 1);
			remain[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> number[i];
	for (int i = 1; i <= 4; i++)
		cin >> remain[i];

	min_answer = 2147483647;
	max_answer = -2147483647;
	dfs(1);

	cout << max_answer << endl << min_answer;
}