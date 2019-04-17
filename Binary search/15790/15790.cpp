#include <iostream>

int n, m, k;
int a[2010];

bool para(int length)
{
	int currentLength = 0, count = 0;

	for (int offset = 0; offset < m; offset++) {
		currentLength = 0;
		count = 0;

		for (int i = 2 + offset; i <= m + offset + 1; i++) {
			currentLength += a[i] - a[i - 1];
			if (currentLength >= length) {
				currentLength = 0;
				count++;
			}
		}

		if (count >= k)
			return true;
	}

	return false;
}

int main()
{
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
		a[i + m] = a[i] + n;
	}

	int s = 1, e = n;
	int middle = (s + e) / 2;
	while (s <= e) {
		if (para(middle)) {
			s = middle + 1;
			middle = (s + e) / 2;
		}
		else {
			e = middle - 1;
			middle = (s + e) / 2;
		}
	}

	if (middle == 0)
		std::cout << "-1";
	else
		std::cout << middle;

	return 0;
}