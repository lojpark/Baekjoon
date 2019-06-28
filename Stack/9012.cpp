#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
vector<int> ort[10010];
vector<int> rev[10010];
vector<int> stack;
vector<vector<int>> scc;
bool visit[10010];

bool cmp(vector<int> arg1, vector<int> arg2)
{
	return arg1[0] < arg2[0];
}

void dfsOrt(int node)
{
	visit[node] = true;

	for (int i = 0; i < (int) ort[node].size(); i++) {
		if (!visit[ort[node][i]]) {
			dfsOrt(ort[node][i]);
		}
	}

	stack.push_back(node);
}
void dfsRev(int node)
{
	visit[node] = true;

	for (int i = 0; i < (int) rev[node].size(); i++) {
		if (!visit[rev[node][i]]) {
			dfsRev(rev[node][i]);
		}
	}

	scc.back().push_back(node);
}

int main()
{
	int s, e;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> e;
		ort[s].push_back(e);
		rev[e].push_back(s);
	}

	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		if (!visit[i])
			dfsOrt(i);
	}

	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		if (!visit[stack.back()]) {
			vector<int> newScc;
			scc.push_back(newScc);
			dfsRev(stack.back());
			sort(scc.back().begin(), scc.back().end());
		}
		stack.pop_back();
	}
	
	sort(scc.begin(), scc.end(), cmp);

	cout << scc.size() << endl;
	for (int i = 0; i < (int) scc.size(); i++) {
		for (int j = 0; j < (int) scc[i].size(); j++) {
			cout << scc[i][j] << " ";
		}
		cout << "-1" << endl;
	}

	return 0;
}