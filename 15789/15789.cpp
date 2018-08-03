#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int c, h, k;
int cpower;
int parent[100010];
int level[100010];
int alliance[100010];
vector<int> power;

bool cmp(int arg1, int arg2)
{
	return arg1 > arg2;
}

int find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void unioN(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	if (level[u] > level[v]) {
		int temp = u;
		u = v;
		v = temp;
	}

	parent[u] = v;

	if (level[u] == level[v])
		level[v]++;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	int input1, input2;
	for (int i = 1; i <= m; i++) {
		cin >> input1 >> input2;
		unioN(input1, input2);
	}

	cin >> c >> h >> k;

	c = find(c);
	h = find(h);

	int temp;
	for (int i = 1; i <= n; i++) {
		temp = find(i);
		if (temp == c)
			cpower++;
		if (temp != c && temp != h)
			alliance[temp]++;
	}

	for (int i = 1; i <= n; i++) {
		if (alliance[i] > 0) {
			power.push_back(alliance[i]);
		}
	}

	std::sort(power.begin(), power.end(), cmp);

	for (int i = 0; i < k; i++) {
		cpower += power[i];
	}

	cout << cpower;

	return 0;
}