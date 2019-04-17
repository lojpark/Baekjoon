#include <iostream>
#include <queue>

using namespace std;

int n, k, l;
int a[110][110];
char r[10010];

enum {
	UP, DOWN, LEFT, RIGHT, SNAKE, APPLE
};

struct Position {
	int x, y;
};

struct Snake {
	int x, y;
	int dir;
	queue<Position> tail;
}s;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> y >> x;
		a[y][x] = APPLE;
	}
	cin >> l;
	for (int i = 1; i <= l; i++) {
		int x;
		char dir;
		cin >> x >> dir;
		r[x] = dir;
	}

	s.dir = RIGHT;
	s.x = s.y = 1;
	s.tail.push({ s.x, s.y });
	a[s.y][s.x] = SNAKE;

	int t;
	for (t = 1; ; t++) {
		if (s.dir == UP) s.y--;
		if (s.dir == DOWN) s.y++;
		if (s.dir == LEFT) s.x--;
		if (s.dir == RIGHT) s.x++;

		if (s.x < 1 || s.y < 1 || s.x > n || s.y > n)
			break;
		if (a[s.y][s.x] == SNAKE)
			break;
		else if (a[s.y][s.x] == APPLE) {
			a[s.y][s.x] = SNAKE;
			s.tail.push({ s.x, s.y });
		}
		else {
			a[s.y][s.x] = SNAKE;
			a[s.tail.front().y][s.tail.front().x] = 0;
			s.tail.pop();
			s.tail.push({ s.x, s.y });
		}

		if (r[t] == 'L') {
			if (s.dir == UP) s.dir = LEFT;
			else if (s.dir == DOWN) s.dir = RIGHT;
			else if (s.dir == LEFT) s.dir = DOWN;
			else if (s.dir == RIGHT) s.dir = UP;
		}
		else if (r[t] == 'D') {
			if (s.dir == UP) s.dir = RIGHT;
			else if (s.dir == DOWN) s.dir = LEFT;
			else if (s.dir == LEFT) s.dir = UP;
			else if (s.dir == RIGHT) s.dir = DOWN;
		}
	}

	cout << t;

	return 0;
}