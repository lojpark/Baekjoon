#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data {
	int node;
	int weight;
};

struct qcmp {
	bool operator()(Data t, Data u) {
		return t.weight > u.weight;
	}
};

int n, m, s;
vector<Data> a[20010];
priority_queue<Data, vector<Data>, qcmp> q;
int d[20010];
bool v[20010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> s;
	int from, to, weight;
	for (int i = 1; i <= m; i++) {
		cin >> from >> to >> weight;
		a[from].push_back({ to, weight });
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 2147483647;
	}

	d[s] = 0;
	q.push({ s, 0 });
	while (!q.empty()) {
		int node = q.top().node;
		int weight = q.top().weight;
		q.pop();

		if (d[node] < weight) {
			continue;
		}

		for (int i = 0; i < (int)a[node].size(); i++) {
			if (d[a[node][i].node] > d[node] + a[node][i].weight) {
				d[a[node][i].node] = d[node] + a[node][i].weight;
				q.push({ a[node][i].node, d[a[node][i].node] });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 2147483647) {
			cout << "INF" << endl;
		}
		else {
			cout << d[i] << endl;
		}
	}
	return 0;
}