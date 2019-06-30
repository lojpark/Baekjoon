#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[110][110];
bool visit[110][110];

struct Data {
	int r, c;
	int count;
};

int bfs()
{
	queue<Data> q;
	int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

	q.push({ 1, 1, 1 });

	while (!q.empty()) {
		Data head = q.front();
		q.pop();

		if (head.r == n && head.c == m)
			return head.count;

		for (int i = 0; i < 4; i++) {
			int to_r = head.r + to[0][i];
			int to_c = head.c + to[1][i];
			if (to_r < 1 || to_r > n || to_c < 1 || to_c > m)
				continue;
			if (!visit[to_r][to_c] && a[to_r][to_c] == '1') {
				visit[to_r][to_c] = true;
				q.push({ to_r, to_c, head.count + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}

	cout << bfs();

	return 0;
}