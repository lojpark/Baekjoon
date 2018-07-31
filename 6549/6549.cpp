#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n;
long long a[100010];
int it[400010];

void init(int node, int start, int end)
{
	if (start == end) {
		it[node] = start;
		return;
	}
	
	int middle = (start + end) >> 1;
	init(node * 2, start, middle);
	init(node * 2 + 1, middle + 1, end);
	
	if (a[it[node * 2]] < a[it[node * 2 + 1]])
		it[node] = it[node * 2];
	else
		it[node] = it[node * 2 + 1];
}
int getMin(int node, int start, int end, int from, int to)
{
	if (from > end || to < start) {
		return -1;
	}
	if (from <= start && end <= to)
		return it[node];
	
	int middle = (start + end) >> 1;
	int left = getMin(node * 2, start, middle, from, to);
	int right = getMin(node * 2 + 1, middle + 1, end, from, to);
	if (left == -1) return right;
	if (right == -1) return left;
	if (a[left] < a[right])
		return left;
	return right;
}

long long divideAndConquer(int start, int end)
{
	int minNode = getMin(1, 1, n, start, end);

	long long area = a[minNode] * (long long)(end - start + 1);

	if (start < minNode) {
		long long left = divideAndConquer(start, minNode - 1);
		if (area < left) area = left;
	}
	if (minNode < end) {
		long long right = divideAndConquer(minNode + 1, end);
		if (area < right) area = right;
	}

	return area;
}

int main()
{
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}

		init(1, 1, n);

		printf("%lld\n", divideAndConquer(1, n));
	}

	return 0;
}