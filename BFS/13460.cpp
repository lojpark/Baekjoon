#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[20][20];
bool v[20][20][20][20];

struct Data {
	int rx, ry;
	int bx, by;
	int len;
};

int main()
{
	queue<Data> q;
	Data head, tail;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R') {
				tail.rx = j;
				tail.ry = i;
			}
			if (a[i][j] == 'B') {
				tail.bx = j;
				tail.by = i;
			}
		}
	}

	tail.len = 0;
	v[tail.bx][tail.by][tail.rx][tail.ry] = true;
	q.push(tail);

	bool is_fail = false, is_success = false, is_r_stuck = false, is_b_stuck = false;
	int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

	while (!q.empty()) {
		head = q.front();
		q.pop();

		if (head.len >= 10)
			continue;

		for (int k = 0; k < 4; k++) {
			tail.rx = tail.ry = tail.bx = tail.by = 0;
			is_fail = is_success = is_r_stuck = is_b_stuck = false;
			for (int i = 1; ; i++) {
				int to_bx = head.bx + to[1][k] * i;
				int to_by = head.by + to[0][k] * i;
				int to_rx = head.rx + to[1][k] * i;
				int to_ry = head.ry + to[0][k] * i;

				if (!is_b_stuck && a[to_by][to_bx] == 'O') {
					is_fail = true;
					break;
				}
				if (!is_r_stuck && a[to_ry][to_rx] == 'O') {
					is_success = true;
				}

				if (!is_b_stuck && a[to_by][to_bx] == '#') {
					tail.bx = to_bx - to[1][k];
					tail.by = to_by - to[0][k];
					is_b_stuck = true;
				}
				if (!is_r_stuck && a[to_ry][to_rx] == '#') {
					tail.rx = to_rx - to[1][k];
					tail.ry = to_ry - to[0][k];
					is_r_stuck = true;
				}

				if (!is_b_stuck && to_bx == tail.rx && to_by == tail.ry) {
					tail.bx = to_bx - to[1][k];
					tail.by = to_by - to[0][k];
					is_b_stuck = true;
				}
				if (!is_r_stuck && to_rx == tail.bx && to_ry == tail.by) {
					tail.rx = to_rx - to[1][k];
					tail.ry = to_ry - to[0][k];
					is_r_stuck = true;
				}
				if (is_b_stuck && is_r_stuck)
					break;
			}
			if (is_fail)
				continue;
			if (is_success) {
				cout << head.len + 1;
				return 0;
			}
			if (!v[tail.bx][tail.by][tail.rx][tail.ry]) {
				tail.len = head.len + 1;
				v[tail.bx][tail.by][tail.rx][tail.ry] = true;
				q.push(tail);
			}
		}
	}
	cout << "-1";
}