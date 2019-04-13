#include <iostream>

using namespace std;

struct Data {
	int x, y;
	int len;
};

int n, m, cn;
int a[51][51];
bool is_closed[3000];
Data chicken[3000];
int answer;

void closure(int index, int count);
int get_chicken_dist(int r, int c);
int get_city_chicken_dist();
int my_abs(int number);

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];

			if (a[i][j] == 2) {
				chicken[++cn].x = j;
				chicken[cn].y = i;
			}
		}
	}

	answer = 2147483647;
	closure(1, 0);

	cout << answer;
	return 0;
}


void closure(int index, int count)
{
	if (index > cn) {
		int dist = get_city_chicken_dist();
		if (dist > 0 && answer > dist) {
			answer = dist;
		}
		return;
	}

	is_closed[index] = true;
	closure(index + 1, count);
	is_closed[index] = false;
	if (count < m) {
		closure(index + 1, count + 1);
	}
}

int get_chicken_dist(int r, int c)
{
	int min = 2147483647;
	for (int i = 1; i <= cn; i++) {
		if (is_closed[i])
			continue;
		if (min > my_abs(r - chicken[i].y) + my_abs(c - chicken[i].x))
			min = my_abs(r - chicken[i].y) + my_abs(c - chicken[i].x);
	}

	if (min == 2147483647)
		return -1;
	return min;
}

int get_city_chicken_dist()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 1)
				continue;

			sum += get_chicken_dist(i, j);
		}
	}
	return sum;
}

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}