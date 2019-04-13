#include <iostream>

using namespace std;

int n, m, x, y, k;
int dice[7];
/*
  2
4 1 3
  5
  6
*/
int a[30][30];

void up()
{
	int temp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = temp;
}
void down()
{
	int temp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = dice[5];
	dice[5] = temp;
}
void left()
{
	int temp = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = dice[4];
	dice[4] = temp;
}
void right()
{
	int temp = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = temp;
}

int main()
{
	cin >> n >> m >> y >> x >> k;
	x++;
	y++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int dir;
		cin >> dir;

		if (dir == 1) {
			if (x >= m)
				continue;
			x++;
			right();
		}
		if (dir == 2) {
			if (x <= 1)
				continue;
			x--;
			left();
		}
		if (dir == 3) {
			if (y <= 1)
				continue;
			y--;
			up();
		}
		if (dir == 4) {
			if (y >= n)
				continue;
			y++;
			down();
		}

		if (a[y][x] == 0) {
			a[y][x] = dice[6];
		}
		else {
			dice[6] = a[y][x];
			a[y][x] = 0;
		}
		cout << dice[1] << endl;
	}
	return 0;
}