#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];

struct Data {
	int value;
	int index;
	bool dir;
}d[100010];

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

bool cmp(Data arg1, Data arg2)
{
	return arg1.value < arg2.value;
}

int main()
{
	int n, l;
	int max = 0, index = 0;

	cin >> n >> l;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i].value = my_abs(a[i]);
		d[i].index = i;
		if (a[i] < 0) {
			d[i].dir = false;
			if (max < my_abs(a[i])) {
				max = my_abs(a[i]);
				index = i;
			}
		}
		else {
			d[i].dir = true;
			if (max < l - my_abs(a[i])) {
				max = l - my_abs(a[i]);
				index = i;
			}
		}
	}

	sort(d + 1, d + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		if (d[i].index == index) {
			index = i;
			break;
		}
	}

	int count = 0;
	if (d[index].dir) {
		for (int i = index + 1; i <= n; i++) {
			if (!d[i].dir)
				count++;
		}
		index += count;
	}
	else {
		for (int i = index - 1; i >= 1; i--) {
			if (d[i].dir)
				count++;
		}
		index -= count;
	}

	cout << d[index].index << " " << max;
	return 0;
}