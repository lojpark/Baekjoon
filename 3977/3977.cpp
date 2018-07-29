#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m;
vector<int> ort[100010];
vector<int> rev[100010];
vector<int> stack;
int sccNumber;
int scc[100010];
int sccIndegree[100010];
bool visit[100010];

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

	scc[node] = sccNumber;
}

int main()
{
	int t;
	int s, e;
	int cnt;

	cin >> t;
	for (; t >= 1; t--) {
		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			cin >> s >> e;
			ort[s].push_back(e);
			rev[e].push_back(s);
		}

		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			if (!visit[i])
				dfsOrt(i);
		}

		sccNumber = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			if (!visit[stack.back()]) {
				sccNumber++;
				dfsRev(stack.back());
			}
			stack.pop_back();
		}

		memset(sccIndegree, 0, sizeof(sccIndegree));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < ort[i].size(); j++) {
				if (scc[i] != scc[ort[i][j]]) {
					sccIndegree[scc[ort[i][j]]]++;
				}
			}
		}

		cnt = 0;
		for (int i = 1; i <= sccNumber; i++) {
			if (sccIndegree[i] == 0) {
				cnt++;
			}
		}

		if (cnt == 1) {
			for (int i = 0; i < n; i++) {
				if (sccIndegree[scc[i]] == 0) {
					cout << i << endl;
				}
			}
		}
		else {
			cout << "Confused" << endl;
		}

		for (int i = 0; i < n; i++) {
			ort[i].clear();
			rev[i].clear();
		}

		cout << endl;
	}

	return 0;
}