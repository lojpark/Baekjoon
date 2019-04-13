#include <iostream>

using namespace std;

char cube[7][4][4];
char color[7] = { 0, 'w', 'y', 'r', 'o', 'g', 'b' };
/*
  4
5 1 6
  3
  2
*/
void rotate_clockwise(int index)
{
	int temp[4][4] = { 0 };
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			temp[i][j] = cube[index][i][j];

	int r = 1, c = 1;
	for (int j = 3; j >= 1; j--) {
		c = 1;
		for (int i = 1; i <= 3; i++) {
			cube[index][i][j] = temp[r][c];
			c++;
		}
		r++;
	}
}

void u(char flag)
{
	if (flag == '+') {
		rotate_clockwise(1);

		int temp[4] = { 0, cube[4][3][1], cube[4][3][2], cube[4][3][3] };
		cube[4][3][1] = cube[5][3][3];
		cube[4][3][2] = cube[5][2][3];
		cube[4][3][3] = cube[5][1][3];
		cube[5][1][3] = cube[3][1][1];
		cube[5][2][3] = cube[3][1][2];
		cube[5][3][3] = cube[3][1][3];
		cube[3][1][1] = cube[6][3][1];
		cube[3][1][2] = cube[6][2][1];
		cube[3][1][3] = cube[6][1][1];
		cube[6][1][1] = temp[1];
		cube[6][2][1] = temp[2];
		cube[6][3][1] = temp[3];
	}
	else {
		u('+');
		u('+');
		u('+');
	}
}
void d(char flag)
{
	if (flag == '+') {
		rotate_clockwise(2);

		int temp[4] = { 0, cube[3][3][1], cube[3][3][2], cube[3][3][3] };
		cube[3][3][1] = cube[5][1][1];
		cube[3][3][2] = cube[5][2][1];
		cube[3][3][3] = cube[5][3][1];
		cube[5][1][1] = cube[4][1][3];
		cube[5][2][1] = cube[4][1][2];
		cube[5][3][1] = cube[4][1][1];
		cube[4][1][1] = cube[6][1][3];
		cube[4][1][2] = cube[6][2][3];
		cube[4][1][3] = cube[6][3][3];
		cube[6][1][3] = temp[3];
		cube[6][2][3] = temp[2];
		cube[6][3][3] = temp[1];
	}
	else {
		d('+');
		d('+');
		d('+');
	}
}
void f(char flag)
{
	if (flag == '+') {
		rotate_clockwise(3);

		int temp[4] = { 0, cube[1][3][1], cube[1][3][2], cube[1][3][3] };
		cube[1][3][1] = cube[5][3][1];
		cube[1][3][2] = cube[5][3][2];
		cube[1][3][3] = cube[5][3][3];
		cube[5][3][1] = cube[2][1][3];
		cube[5][3][2] = cube[2][1][2];
		cube[5][3][3] = cube[2][1][1];
		cube[2][1][1] = cube[6][3][3];
		cube[2][1][2] = cube[6][3][2];
		cube[2][1][3] = cube[6][3][1];
		cube[6][3][1] = temp[1];
		cube[6][3][2] = temp[2];
		cube[6][3][3] = temp[3];
	}
	else {
		f('+');
		f('+');
		f('+');
	}
}
void b(char flag)
{
	if (flag == '+') {
		rotate_clockwise(4);

		int temp[4] = { 0, cube[1][1][1], cube[1][1][2], cube[1][1][3] };
		cube[1][1][1] = cube[6][1][1];
		cube[1][1][2] = cube[6][1][2];
		cube[1][1][3] = cube[6][1][3];
		cube[6][1][1] = cube[2][3][3];
		cube[6][1][2] = cube[2][3][2];
		cube[6][1][3] = cube[2][3][1];
		cube[2][3][1] = cube[5][1][3];
		cube[2][3][2] = cube[5][1][2];
		cube[2][3][3] = cube[5][1][1];
		cube[5][1][1] = temp[1];
		cube[5][1][2] = temp[2];
		cube[5][1][3] = temp[3];
	}
	else {
		b('+');
		b('+');
		b('+');
	}
}
void l(char flag)
{
	if (flag == '+') {
		rotate_clockwise(5);

		int temp[4] = { 0, cube[1][1][1], cube[1][2][1], cube[1][3][1] };
		cube[1][1][1] = cube[4][1][1];
		cube[1][2][1] = cube[4][2][1];
		cube[1][3][1] = cube[4][3][1];
		cube[4][1][1] = cube[2][1][1];
		cube[4][2][1] = cube[2][2][1];
		cube[4][3][1] = cube[2][3][1];
		cube[2][1][1] = cube[3][1][1];
		cube[2][2][1] = cube[3][2][1];
		cube[2][3][1] = cube[3][3][1];
		cube[3][1][1] = temp[1];
		cube[3][2][1] = temp[2];
		cube[3][3][1] = temp[3];
	}
	else {
		l('+');
		l('+');
		l('+');
	}
}
void r(char flag)
{
	if (flag == '+') {
		rotate_clockwise(6);

		int temp[4] = { 0, cube[1][1][3], cube[1][2][3], cube[1][3][3] };
		cube[1][1][3] = cube[3][1][3];
		cube[1][2][3] = cube[3][2][3];
		cube[1][3][3] = cube[3][3][3];
		cube[3][1][3] = cube[2][1][3];
		cube[3][2][3] = cube[2][2][3];
		cube[3][3][3] = cube[2][3][3];
		cube[2][1][3] = cube[4][1][3];
		cube[2][2][3] = cube[4][2][3];
		cube[2][3][3] = cube[4][3][3];
		cube[4][1][3] = temp[1];
		cube[4][2][3] = temp[2];
		cube[4][3][3] = temp[3];
	}
	else {
		r('+');
		r('+');
		r('+');
	}
}

int main()
{
	int t, n;
	cin >> t;
	for (; t >= 1; t--) {
		for (int k = 1; k <= 6; k++) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					cube[k][i][j] = color[k];
				}
			}
		}

		cin >> n;
		for (int i = 1; i <= n; i++) {
			char dir, flag;
			cin >> dir >> flag;
			switch (dir) {
			case 'U':
				u(flag);
				break;
			case 'D':
				d(flag);
				break;
			case 'F':
				f(flag);
				break;
			case 'B':
				b(flag);
				break;
			case 'L':
				l(flag);
				break;
			case 'R':
				r(flag);
				break;
			default:
				break;
			}
		}

		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cout << cube[1][i][j];
			}
			cout << endl;
		}
	}
	return 0;
}