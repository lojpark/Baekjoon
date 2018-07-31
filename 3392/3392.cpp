#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
	int x;
	int y1, y2;
	bool isStart;
}query[20010];

int n;
int it[120010], cnt[120010];

bool cmp(Data arg1, Data arg2)
{
	return arg1.x < arg2.x;
}

void update(int node, int start, int end, int from, int to, int diff)
{
	if (from > end || to < start)
		return;

	if (from <= start && end <= to)
		cnt[node] += diff;
	
	else {
		int middle = (start + end) / 2;
		update(node * 2, start, middle, from, to, diff);
		update(node * 2 + 1, middle + 1, end, from, to, diff);
	}

	if (cnt[node]) {
		it[node] = end - start + 1;
	}
	else {
		if (start == end) it[node] = 0;
		else it[node] = it[node * 2] + it[node * 2 + 1];
	}
}

int main()
{
	int input[4];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> input[j];
		}
		query[i].x = input[0];
		query[i].y1 = input[1];
		query[i].y2 = input[3] - 1;
		query[i].isStart = true;

		query[n + i].x = input[2];
		query[n + i].y1 = input[1];
		query[n + i].y2 = input[3] - 1;
		query[n + i].isStart = false;
	}

	sort(query + 1, query + 1 + n * 2, cmp);

	int sum = 0;
	for (int i = 1; i <= n * 2; i++) {
		if (i > 1)
			sum += (query[i].x - query[i - 1].x) * it[1];
		if (query[i].isStart)
			update(1, 0, 30000, query[i].y1, query[i].y2, 1);
		else
			update(1, 0, 30000, query[i].y1, query[i].y2, -1);
	}

	if (n == 1)
		cout << (input[2] - input[0]) * (input[3] - input[1]);
	else
		cout << sum;

	return 0;
}