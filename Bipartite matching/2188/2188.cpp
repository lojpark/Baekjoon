#include <iostream>

using namespace std;

int n, m;
int s[210];
bool adj[210][210];
int cow[210];
int shed[210];
bool visit[210];

bool dfs(int node)
{
	if (visit[node])
		return false;
	visit[node] = true;

	for (int i = 1; i <= m; i++) {
		if (adj[node][i]) {
			if (shed[i] == 0 || dfs(shed[i])) {
				// Mathcing
				cow[node] = i;
				shed[i] = node;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++) {
			int input;
			cin >> input;
			adj[i][input] = 1;
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			visit[j] = false;

		if (dfs(i))
			answer++;
	}

	cout << answer << endl;

	return 0;
}