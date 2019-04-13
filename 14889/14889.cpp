#include <iostream>
#include <vector>

using namespace std;

int n;
int a[30][30];
int answer;
vector<int> start, link;

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

void dfs(int index)
{
	if (index == n + 1) {
		int start_score = 0, link_score = 0;
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= n / 2; j++) {
				start_score += a[start[i - 1]][start[j - 1]];
				link_score += a[link[i - 1]][link[j - 1]];
			}
		}
		if (answer > my_abs(start_score - link_score))
			answer = my_abs(start_score - link_score);
		return;
	}

	if (start.size() < n / 2) {
		start.push_back(index);
		dfs(index + 1);
		start.pop_back();
	}

	if (link.size() < n / 2) {
		link.push_back(index);
		dfs(index + 1);
		link.pop_back();
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}

	answer = 2147483647;
	dfs(1);

	cout << answer;
	return 0;
}