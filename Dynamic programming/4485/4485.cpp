#include <iostream>
#include <queue>

using namespace std;

int n;
int a[150][150];
int d[150][150];
int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

struct Item {
	int x, y;
};

queue<Item> q;

int main()
{

	for (int k = 1; ; k++) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++) {
				a[i][j] = -1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				d[i][j] = 2147483647;
			}
		}

		Item head, tail;
		d[1][1] = a[1][1];
		tail.x = tail.y = 1;
		q.push(tail);
		while (!q.empty()) {
			head = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (a[head.y + to[0][i]][head.x + to[1][i]] == -1)
					continue;
				if (d[head.y + to[0][i]][head.x + to[1][i]] > d[head.y][head.x] + a[head.y + to[0][i]][head.x + to[1][i]]) {
					d[head.y + to[0][i]][head.x + to[1][i]] = d[head.y][head.x] + a[head.y + to[0][i]][head.x + to[1][i]];
					tail.y = head.y + to[0][i];
					tail.x = head.x + to[1][i];
					q.push(tail);
				}
			}
		}

		cout << "Problem " << k << ": " << d[n][n] << endl;
	}

	return 0;
}