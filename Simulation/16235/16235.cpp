#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Tree {
	int age;
	bool is_alive;
};

int n, m, k;
int a[20][20];
int energy[20][20];
vector<Tree> land[20][20];
bool cmp(Tree arg1, Tree arg2)
{
	return arg1.age < arg2.age;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			energy[i][j] = 5;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y, age;
		cin >> y >> x >> age;
		land[y][x].push_back({ age, true });
	}

	int to[2][8] = { {-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, 1, 0, -1, -1} };

	for (; k >= 1; k--) {
		// Spring
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// Sort (Young ~ Old)
				sort(land[i][j].begin(), land[i][j].end(), cmp);
				for (int index = 0; index < (int)land[i][j].size(); index++) {
					// Death
					if (energy[i][j] < land[i][j][index].age)
						land[i][j][index].is_alive = false;
					// Grow
					else {
						energy[i][j] -= land[i][j][index].age;
						land[i][j][index].age++;
					}
				}
			}
		}

		// Summer
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int index = (int)land[i][j].size() - 1; index >= 0; index--) {
					// Add energy & Erase dead trees
					if (!land[i][j][index].is_alive) {
						energy[i][j] += (int)(land[i][j][index].age / 2);
						land[i][j].erase(land[i][j].begin() + index);
					}
				}
			}
		}

		// Fall
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int index = (int)land[i][j].size() - 1; index >= 0; index--) {
					// Breed
					if (land[i][j][index].age % 5 == 0) {
						for (int ti = 0; ti < 8; ti++) {
							int to_x = j + to[1][ti];
							int to_y = i + to[0][ti];
							if (to_x < 1 || to_y < 1 || to_x > n || to_y > n)
								continue;
							land[to_y][to_x].push_back({ 1, true });
						}
					}
				}
			}
		}

		// Winter
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// Add energy
				energy[i][j] += a[i][j];
			}
		}
	}

	int answer = 0;
	// Count alive trees
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer += (int)land[i][j].size();
		}
	}

	cout << answer;
}