#include <iostream>
#include <string>
#include <queue>

using namespace std;

enum {
	EMPTY = '.', HERO = '@', ROBOT = '+', FASTBOT = '#', JUNKHEAP = '*'
};

struct Data {
	int r, c;
	int type;
};

string a[1010];
Data hero;

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

int my_max(int t, int u)
{
	if (t > u)
		return t;
	return u;
}

struct qcmp {
	bool operator()(Data t, Data u) {
		return my_max(my_abs(hero.r - t.r), my_abs(hero.c - t.c)) > my_max(my_abs(hero.r - u.r), my_abs(hero.c - u.c));
	}
};

priority_queue<Data, vector<Data>, qcmp> robots[2], fast_robots;

int main()
{
	int k = 0;
	while (getline(cin, a[k])) {
		if (a[k] == "$") {
			int n = k, m = (int)a[0].size();
			int answer = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == HERO) {
						hero = { i, j, HERO };
						i = n;
						break;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == ROBOT || a[i][j] == FASTBOT)
						robots[0].push({ i, j, a[i][j] });
				}
			}

			Data head;
			int flag = 0;
			while (!robots[flag].empty()) {
				while (!robots[flag].empty()) {
					head = robots[flag].top();
					robots[flag].pop();

					if (a[head.r][head.c] == JUNKHEAP)
						continue;
					a[head.r][head.c] = '.';

					if (head.r < hero.r)
						head.r++;
					else if (head.r > hero.r)
						head.r--;
					if (head.c < hero.c)
						head.c++;
					else if (head.c > hero.c)
						head.c--;

					if (a[head.r][head.c] == HERO)
						answer++;
					else if (a[head.r][head.c] == EMPTY) {
						a[head.r][head.c] = head.type;
						if (head.type == ROBOT)
							robots[1 - flag].push(head);
						else if (head.type == FASTBOT)
							fast_robots.push(head);
					}
					else
						a[head.r][head.c] = JUNKHEAP;
				}

				while (!fast_robots.empty()) {
					head = fast_robots.top();
					fast_robots.pop();

					if (a[head.r][head.c] == JUNKHEAP)
						continue;
					a[head.r][head.c] = '.';

					if (head.r < hero.r)
						head.r++;
					else if (head.r > hero.r)
						head.r--;
					if (head.c < hero.c)
						head.c++;
					else if (head.c > hero.c)
						head.c--;

					if (a[head.r][head.c] == HERO)
						answer++;
					else if (a[head.r][head.c] == EMPTY) {
						a[head.r][head.c] = head.type;
						robots[1 - flag].push(head);
					}
					else
						a[head.r][head.c] = JUNKHEAP;
				}
				flag = 1 - flag;
			}

			cout << answer << endl;

			k = -1;
		}
		k++;
	}

	return 0;
}