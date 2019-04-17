#include <iostream>
#include <bitset>

using namespace std;

int n, m;
char a[21][21];
int to[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
bitset<410> visit;
bitset<26> chk;
int answer;

void dfs(int r, int c, int depth)
{
	if (answer < depth)
		answer = depth;
	for (int i = 0; i < 4; i++) {
		int toR = r + to[0][i];
		int toC = c + to[1][i];

		if (a[toR][toC] < 'A' || a[toR][toC] > 'Z') continue;
		if (!visit[(toR - 1) * m + toC - 1] && !chk[a[toR][toC] - 'A']) {
			visit[(toR - 1) * m + toC - 1] = true;
			chk[a[toR][toC] - 'A'] = true;
			dfs(toR, toC, depth + 1);
			visit[(toR - 1) * m + toC - 1] = false;
			chk[a[toR][toC] - 'A'] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> (a[i] + 1);
	}

	visit.reset();
	chk.reset();
	chk[a[1][1] - 'A'] = true;
	visit[0] = true;
	dfs(1, 1, 1);

	cout << answer;

	return 0;
}