#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
vector<int> a[1010];
bool visit[1010];

void dfs(int node)
{
	cout << node << " ";
	for (int i = 0; i < (int)a[node].size(); i++) {
		if (!visit[a[node][i]]) {
			visit[a[node][i]] = true;
			dfs(a[node][i]);
		}
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();

		cout << node << " ";

		for (int i = 0; i < (int)a[node].size(); i++) {
			if (!visit[a[node][i]]) {
				visit[a[node][i]] = true;
				q.push(a[node][i]);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());

	visit[v] = true;
	dfs(v);
	cout << endl;

	for (int i = 1; i <= n; i++)
		visit[i] = false;

	visit[v] = true;
	bfs(v);

	return 0;
}