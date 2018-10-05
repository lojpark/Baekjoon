#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
vector<int> ort[20001];
vector<int> rev[20001];
vector<int> stack;
vector<vector<int>> scc;
bool visit[20001];

bool cmp(vector<int> arg1, vector<int> arg2)
{
	return arg1[0] < arg2[0];
}

void dfsOrt(int node)
{
	visit[node] = true;

	for (int i = 0; i < (int)ort[node].size(); i++) {
		if (!visit[ort[node][i]]) {
			dfsOrt(ort[node][i]);
		}
	}

	stack.push_back(node);
}
void dfsRev(int node)
{
	visit[node] = true;

	for (int i = 0; i < (int)rev[node].size(); i++) {
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
		ort[s * -1 + n].push_back(e + n);
		rev[e + n].push_back(s * -1 + n);
		ort[e * -1 + n].push_back(s + n);
		rev[s + n].push_back(e * -1 + n);
	}

	memset(visit, false, sizeof(visit));
	for (int i = 0; i <= n * 2; i++) {
		if (!visit[i])
			dfsOrt(i);
	}

	memset(visit, false, sizeof(visit));
	for (int i = 0; i <= n * 2; i++) {
		if (!visit[stack.back()]) {
			vector<int> newScc;
			scc.push_back(newScc);
			dfsRev(stack.back());
			sort(scc.back().begin(), scc.back().end());
		}
		stack.pop_back();
	}

	sort(scc.begin(), scc.end(), cmp);

	for (int i = 0; i < (int)scc.size(); i++) {
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < (int)scc[i].size(); j++) {
			if (visit[scc[i][j]]) {
				cout << "0";
				return 0;
			}
			if (scc[i][j] - n > 0) {
				visit[scc[i][j] - n] = true;
			}
			else {
				visit[(scc[i][j] - n) * -1 + n] = true;
			}
		}
	}

	cout << "1";
	return 0;
}