#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100010];
bool visit[100010];
bool isCycled[100010];
bool trash[100010];
vector<int> cycle;

void dfs(int node)
{
	if (trash[a[node]] || isCycled[a[node]]) {
		int m = cycle.size();
		for (int i = 0; i < m; i++)
			trash[cycle[i]] = true;
		return;
	}
	if (!visit[a[node]]) {
		visit[a[node]] = true;
		cycle.push_back(a[node]);
		dfs(a[node]);
		visit[a[node]] = false;
	}
	else {
		int m = cycle.size();
		bool check = false;

		for (int i = 0; i < m; i++) {
			if (cycle[i] == a[node])
				check = true;
			if (check)
				isCycled[cycle[i]] = true;
			else
				trash[cycle[i]] = true;
		}
		return;
	}
}

int main()
{
	int t;
	cin >> t;

	for (; t > 0; t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!isCycled[i] && !trash[i]) {
				cycle.clear();
				cycle.push_back(i);
				visit[i] = true;
				dfs(i);
				visit[i] = false;
			}
		}

		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (!isCycled[i])
				count++;
			isCycled[i] = false;
			trash[i] = false;
		}
		cout << count << endl;
	}
	return 0;
}