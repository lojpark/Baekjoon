#include <iostream>

using namespace std;

int main()
{
	int x, y;
	int first_day[13] = { 0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };
	int day;

	cin >> x >> y;

	day = first_day[x];
	for (int i = 2; i <= y; i++)
		day = (day + 1) % 7;

	switch (day) {
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	default:
		break;
	}

	return 0;
}