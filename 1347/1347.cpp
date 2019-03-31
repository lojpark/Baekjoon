#include <iostream>

using namespace std;

int n;
char a[51];
bool map[110][110];
int min_x, min_y, max_x, max_y;
int x, y, dir;

enum {
	UP, DOWN, LEFT, RIGHT
};


void turn_left();
void turn_right();
void go_forward();

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	min_x = min_y = 110;
	max_x = max_y = 0;
	x = y = 51;
	dir = DOWN;

	for (int i = 0; i <= n; i++) {
		if (a[i] == 'F') go_forward();
		if (a[i] == 'L') turn_left();
		if (a[i] == 'R') turn_right();

		map[y][x] = true;

		if (min_x > x) min_x = x;
		if (min_y > y) min_y = y;
		if (max_x < x) max_x = x;
		if (max_y < y) max_y = y;
	}

	for (int i = min_y; i <= max_y; i++) {
		for (int j = min_x; j <= max_x; j++) {
			if (map[i][j]) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}

	return 0;
}


void turn_left()
{
	switch (dir) {
	case UP:
		dir = LEFT;
		break;
	case DOWN:
		dir = RIGHT;
		break;
	case LEFT:
		dir = DOWN;
		break;
	case RIGHT:
		dir = UP;
		break;
	}
}
void turn_right()
{
	switch (dir) {
	case UP:
		dir = RIGHT;
		break;
	case DOWN:
		dir = LEFT;
		break;
	case LEFT:
		dir = UP;
		break;
	case RIGHT:
		dir = DOWN;
		break;
	}
}
void go_forward()
{
	switch (dir) {
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}
}