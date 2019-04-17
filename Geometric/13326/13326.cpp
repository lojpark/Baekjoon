/*
Geometric
*/
#include <iostream>
#include <algorithm>
#include <math.h>

int n;
struct Data{
	double x, y;
}a[5010], pivot;

double dist(Data one, Data two)
{
	return sqrt((one.x - two.x) * (one.x - two.x) + (one.y - two.y) * (one.y - two.y));
}

bool cmp(Data one, Data two)
{
	return dist(pivot, one) < dist(pivot, two);
}

int main()
{
	int i, j, k;
	std::cin >> n;
	for (i = 1; i <= n; i++) {
		std::cin >> a[i].x >> a[i].y;
	}

	int mi = 0;
	double max = 0, max2 = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (max < dist(a[i], a[j])) {
				max = dist(a[i], a[j]);
				mi = i;
			}
		}
	}

	pivot = a[mi];
	std::sort(a + 1, a + 1 + n, cmp);

	double answer = max;
	double nmMax[5010] = {0}, revMax[5010] = {0};

	for (i = 1; i <= n; i++) {
		nmMax[i] = nmMax[i - 1];
		for (j = 1; j <= i; j++) {
			if (nmMax[i] < dist(a[i], a[j]))
				nmMax[i] = dist(a[i], a[j]);
		}
	}

	for (i = n; i >= 1; i--) {
		revMax[i] = revMax[i + 1];
		for (j = n; j >= i; j--) {
			if (revMax[i] < dist(a[i], a[j]))
				revMax[i] = dist(a[i], a[j]);
		}
	}

	for (k = 2; k <= n; k++) {
		if (answer > nmMax[k - 1] + revMax[k])
			answer = nmMax[k - 1] + revMax[k];
	}

	printf("%.4lf\n", answer);
}