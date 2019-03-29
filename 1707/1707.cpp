#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> e[20010];
int colors[20010];

bool dfs(int node, int color)
{
	colors[node] = color;
	for (int i = 0; i < (int)e[node].size(); i++) {
		if (colors[e[node][i]] == 0) {
			if (!dfs(e[node][i], 3 - color))
				return false;
		}
		else if (colors[e[node][i]] != 3 - color)
			return false;
	}
	return true;
}

int main()
{
	int t, i;

	cin >> t;

	for (; t > 0; t--) {
		cin >> n >> m;

		for (i = 1; i <= n; i++) {
			e[i].clear();
			colors[i] = 0;
		}

		for (i = 1; i <= m; i++) {
			int from, to;
			cin >> from >> to;
			e[from].push_back(to);
			e[to].push_back(from);
		}

		for (i = 1; i <= n; i++) {
			if (colors[i] == 0) {
				if (!dfs(i, 1)) {
					i = 0;
					break;
				}
			}
		}
		if (i == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}