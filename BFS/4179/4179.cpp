#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[1010][1010];
bool v[1010][1010];

struct Data {
	bool type; // false: Jihoon, true: Fire
	int x, y;
	int len;
};

queue<Data> q;

int main()
{

	Data head, tail; 

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];

			if (a[i][j] == 'F')
				q.push({ true, j, i, 0 });
			if (a[i][j] == 'J') {
				tail.x = j;
				tail.y = i;
				a[i][j] = '.';
				v[i][j] = true;
			}
		}
	}

	tail.type = false;
	tail.len = 0;
	q.push(tail);

	int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

	while (!q.empty()) {
		head = q.front();
		q.pop();

		tail.type = head.type;
		// Fire
		if (head.type) {
			for (int i = 0; i < 4; i++) {
				int to_x = head.x + to[1][i];
				int to_y = head.y + to[0][i];
				if (a[to_y][to_x] == '.') {
					a[to_y][to_x] = 'F';
					tail.x = to_x;
					tail.y = to_y;
					q.push(tail);
				}
			}
		}
		// Jihoon
		else {
			for (int i = 0; i < 4; i++) {
				int to_x = head.x + to[1][i];
				int to_y = head.y + to[0][i];
				if (to_x < 1 || to_x > m || to_y < 1 || to_y > n) {
					cout << head.len + 1;
					return 0;
				}
				if (a[to_y][to_x] == '.' && !v[to_y][to_x]) {
					v[to_y][to_x] = true;
					tail.x = to_x;
					tail.y = to_y;
					tail.len = head.len + 1;
					q.push(tail);
				}
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}