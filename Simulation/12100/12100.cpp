#include <iostream>

using namespace std;

int n;
int a[30][30], original[30][30];
int dirc[6];
int answer;

void up()
{
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i < n; i++) {
				if (a[i][j] == 0) {
					a[i][j] = a[i + 1][j];
					a[i + 1][j] = 0;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (a[i][j] == a[i + 1][j]) {
				a[i][j] += a[i + 1][j];
				a[i + 1][j] = 0;
			}
			if (answer < a[i][j])
				answer = a[i][j];
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i < n; i++) {
				if (a[i][j] == 0) {
					a[i][j] = a[i + 1][j];
					a[i + 1][j] = 0;
				}
			}
		}
	}
}
void down()
{
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			for (int i = n; i > 1; i--) {
				if (a[i][j] == 0) {
					a[i][j] = a[i - 1][j];
					a[i - 1][j] = 0;
				}
			}
		}
		for (int i = n; i > 1; i--) {
			if (a[i][j] == a[i - 1][j]) {
				a[i][j] += a[i - 1][j];
				a[i - 1][j] = 0;
			}
			if (answer < a[i][j])
				answer = a[i][j];
		}
		for (int k = 1; k <= n; k++) {
			for (int i = n; i > 1; i--) {
				if (a[i][j] == 0) {
					a[i][j] = a[i - 1][j];
					a[i - 1][j] = 0;
				}
			}
		}
	}
}
void left()
{
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j < n; j++) {
				if (a[i][j] == 0) {
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = 0;
				}
			}
		}
		for (int j = 1; j < n; j++) {
			if (a[i][j] == a[i][j + 1]) {
				a[i][j] += a[i][j + 1];
				a[i][j + 1] = 0;
			}
			if (answer < a[i][j])
				answer = a[i][j];
		}
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j < n; j++) {
				if (a[i][j] == 0) {
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = 0;
				}
			}
		}
	}
}
void right()
{
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int j = n; j > 1; j--) {
				if (a[i][j] == 0) {
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = 0;
				}
			}
		}
		for (int j = n; j > 1; j--) {
			if (a[i][j] == a[i][j - 1]) {
				a[i][j] += a[i][j - 1];
				a[i][j - 1] = 0;
			}
			if (answer < a[i][j])
				answer = a[i][j];
		}
		for (int k = 1; k <= n; k++) {
			for (int j = n; j > 1; j--) {
				if (a[i][j] == 0) {
					a[i][j] = a[i][j - 1];
					a[i][j - 1] = 0;
				}
			}
		}
	}
}

void dfs(int index)
{
	if (index > 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = original[i][j];
			}
		}
		for (int i = 1; i < index; i++) {
			if (dirc[i] == 1) up();
			if (dirc[i] == 2) down();
			if (dirc[i] == 3) right();
			if (dirc[i] == 4) left();
		}
	}
	if (index > 5)
		return;

	for (int i = 1; i <= 4; i++) {
		dirc[index] = i;
		dfs(index + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> original[i][j];
			if (answer < original[i][j])
				answer = original[i][j];
		}
	}

	dfs(1);

	cout << answer;
	return 0;
}