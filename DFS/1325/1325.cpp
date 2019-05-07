#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m;
vector<int> a[10010];
int d[10010];
bool v[10010];
int max_d;

int dfs(int node)
{
	v[node] = true;

	int my_n = (int)a[node].size();
	int count = 0;
	for (int i = 0; i < my_n; i++) {
		if (!v[a[node][i]])
			count += dfs(a[node][i]) + 1;
	}
	if (max_d < count)
		max_d = count;

	return count;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int input_a, input_b;
		cin >> input_a >> input_b;
		a[input_b].push_back(input_a);
	}

	max_d = 0;
	for (int i = 1; i <= n; i++) {
		memset(v, false, sizeof(v));
		d[i] = dfs(i);
	}

	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		if (d[i] == max_d)
			answer.push_back(i);
	}

	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}