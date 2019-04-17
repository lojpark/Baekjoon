#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
vector<int> ort[100010];
vector<int> rev[100010];
vector<int> stack;
int sccNumber;
int scc[100010];
int sccOutdegree[100010];
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
	int s, e;

	while (true) {
		cin >> n;
		if (n == 0) break;
		cin >> m;

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

		sccNumber = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			if (!visit[stack.back()]) {
				sccNumber++;
				dfsRev(stack.back());
			}
			stack.pop_back();
		}

		memset(sccOutdegree, 0, sizeof(sccOutdegree));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (int) ort[i].size(); j++) {
				if (scc[i] != scc[ort[i][j]]) {
					sccOutdegree[scc[i]]++;
				}
			}
		}

		vector<int> answer;
		for (int i = 1; i <= sccNumber; i++) {
			if (sccOutdegree[i] == 0) {
				for (int j = 1; j <= n; j++) {
					if (scc[j] == i) answer.push_back(j);
				}
			}
		}

		sort(answer.begin(), answer.end());

		for (int i = 0; i < (int) answer.size(); i++) {
			cout << answer[i] << " ";
		}

		cout << endl;

		for (int i = 1; i <= n; i++) {
			ort[i].clear();
			rev[i].clear();
		}
	}

	return 0;
}