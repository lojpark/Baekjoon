#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[110][110];
bool v[110][110];
struct Data {
	int x, y;
	int count;
};
queue<Data> q;

void push_laser(int x, int y, int count);

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'C') {
				push_laser(j, i, 0);
				v[i][j] = true;
				a[i][j] = '.';
				i = n;
				break;
			}
		}
	}

	Data head;
	while (!q.empty())
	{
		head = q.front();
		q.pop();

		if (a[head.y][head.x] == 'C') {
			cout << head.count;
			return 0;
		}

		push_laser(head.x, head.y, head.count + 1);
	}

	return 0;
}

void push_laser(int x, int y, int count)
{
	// Up
	for (int i = 1; y - i >= 1; i++) {
		if (a[y - i][x] == '*')
			break;
		if (v[y - i][x])
			continue;
		v[y - i][x] = true;
		q.push({ x, y - i, count });
	}
	// Down
	for (int i = 1; y + i <= n; i++) {
		if (a[y + i][x] == '*')
			break;
		if (v[y + i][x])
			continue;
		v[y + i][x] = true;
		q.push({ x, y + i, count });
	}
	// Left
	for (int i = 1; x - i >= 1; i++) {
		if (a[y][x - i] == '*')
			break;
		if (v[y][x - i])
			continue;
		v[y][x - i] = true;
		q.push({ x - i, y, count });
	}
	// Right
	for (int i = 1; x + i <= m; i++) {
		if (a[y][x + i] == '*')
			break;
		if (v[y][x + i])
			continue;
		v[y][x + i] = true;
		q.push({ x + i, y, count });
	}
}