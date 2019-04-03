#include <iostream>

using namespace std;

int n;
struct Data {
	long long int x, y;
}a[10010], p[4], pivot;

int small(long long int number)
{
	if (number > 0)
		return 1;
	else if (number < 0)
		return -1;
	return 0;
}

long long int ccw(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
}

bool is_cross(Data s1, Data e1, Data s2, Data e2)
{
	if (small(ccw(s1.x, s1.y, e1.x, e1.y, s2.x, s2.y)) * small(ccw(s1.x, s1.y, e1.x, e1.y, e2.x, e2.y)) <= 0) {
		if (small(ccw(s2.x, s2.y, e2.x, e2.y, s1.x, s1.y)) * small(ccw(s2.x, s2.y, e2.x, e2.y, e1.x, e1.y)) <= 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	a[n + 1].x = a[1].x;
	a[n + 1].y = a[1].y;

	for (int i = 1; i <= 3; i++) {
		cin >> p[i].x >> p[i].y;
	}

	int count = 0;
	pivot.x = 1781237721;
	pivot.y = 1784639483;

	for (int k = 1; k <= 3; k++) {
		count = 0;
		for (int i = 1; i <= n; i++) {
			// 경계선 위에 걸칠 경우 무조건 내부 처리
			if (ccw(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y, p[k].x, p[k].y) == 0) {
				count = 1;
				break;
			}
			if (is_cross(p[k], pivot, a[i], a[i + 1]))
				count++;
		}
		if (count % 2 == 0)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}

	return 0;
}