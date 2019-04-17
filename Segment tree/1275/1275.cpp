#include <stdio.h>

int n, m;
long long a[100010];
long long it[400010];

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
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}

	init(1, 1, n);

	int X, Y, A, temp;
	long long B;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &X, &Y);

		if (X > Y) {
			temp = X;
			X = Y;
			Y = temp;
		}

		printf("%lld\n", sum(1, 1, n, X, Y));

		scanf("%d%lld", &A, &B);
		update(1, 1, n, A, B - a[A]);
		a[A] = B;
	}

	return 0;
}