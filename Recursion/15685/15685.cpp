#include <iostream>

using namespace std;

int x, y, d;
bool a[110][110];

void dragon_curve(int g, bool is_reversed)
{
	if (g == 0) {
		switch (d) {
		case 0:
			x++;
			break;
		case 1:
			y--;
			break;
		case 2:
			x--;
			break;
		case 3:
			y++;
			break;
		}
		a[y][x] = true;
		return;
	}

	dragon_curve(g - 1, false);

	if (!is_reversed)
		d++;
	else
		d--;

	if (d < 0)
		d = 3;
	if (d > 3)
		d = 0;

	dragon_curve(g - 1, true);
}

int main()
{
	int n, g;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> d >> g;
		a[y][x] = true;
		dragon_curve(g, false);
	}
	
	int count = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1])
				count++;
		}
	}

	cout << count;

	return 0;
}