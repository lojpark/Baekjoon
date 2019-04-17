#include <iostream>

using namespace std;

int n, m, k;
long long a[1000010];
long long it[4000010];

long long init(int node, int start, int end)
{
	if (start > end) return 0;

	if (start == end) {
		return it[node] = a[start];
	}

	int middle = (start + end) / 2;
	return it[node] = init(node * 2, start, middle) + init(node * 2 + 1, middle + 1, end);
}

void update(int node, int start, int end, int index, long long diff)
{
	if (index < start || end < index)
		return;

	it[node] += diff;

	if (start < end)
	{
		int middle = (start + end) / 2;
		update(node * 2, start, middle, index, diff);
		update(node * 2 + 1, middle + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int from, int to)
{
	if (from > end || to < start)
		return 0;

	if (from <= start && end <= to)
		return it[node];

	int middle = (start + end) / 2;
	return sum(node * 2, start, middle, from, to) + sum(node * 2 + 1, middle + 1, end, from, to);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	init(1, 1, n);

	int input1, input2, input3;
	for (int i = 1; i <= m + k; i++) {
		cin >> input1 >> input2 >> input3;
		if (input1 == 1) {
			update(1, 1, n, input2, input3 - a[input2]);
			a[input2] = input3;
		}
		else {
			cout << sum(1, 1, n, input2, input3) << endl;
		}
	}

	return 0;
}