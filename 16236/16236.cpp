#include <iostream>
#include <queue>

using namespace std;

int n;
int a[30][30];
int answer;

struct Data {
	int x, y;
	int len;
};

Data bfs(int x, int y, int size)
{
	int to[2][4] = { {-1, 1, 0, 0}, {0, 0 ,-1, 1} };
	bool visit[30][30] = { false };
	queue<Data> q, candidate;
	Data head, ret = { 2147483647, 2147483647, false };
	int shortest_len = -1;

	visit[y][x] = true;
	q.push({ x, y, 0 });

	while (!q.empty()) {
		head = q.front();
		q.pop();

		if (shortest_len != -1 && head.len > shortest_len)
			break;

		for (int i = 0; i < 4; i++) {
			int to_x = head.x + to[1][i];
			int to_y = head.y + to[0][i];
			if (to_x < 1 || to_y < 1 || to_x > n || to_y > n)
				continue;
			if (a[to_y][to_x] > size || visit[to_y][to_x])
				continue;
			if (a[to_y][to_x] < size && a[to_y][to_x] != 0) {
				shortest_len = head.len;
				candidate.push({ to_x, to_y, head.len + 1 });
			}

			visit[to_y][to_x] = true;
			q.push({ to_x, to_y, head.len + 1 });
		}
	}

	while (!candidate.empty()) {
		head = candidate.front();
		candidate.pop();

		if (ret.y > head.y)
			ret = head;
		else if (ret.y == head.y && ret.x > head.x)
			ret = head;
	}

	return ret;
}

int main()
{
	Data shark;
	int size = 2, eat = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				shark.x = j;
				shark.y = i;
				a[i][j] = 0;
			}
		}
	}

	while ((shark = bfs(shark.x, shark.y, size)).len) {
		answer += shark.len;
		a[shark.y][shark.x] = 0;
		eat++;
		if (eat >= size) {
			size++;
			eat = 0;
		}
	}

	cout << answer;
}