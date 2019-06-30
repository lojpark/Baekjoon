#include <iostream>
#include <queue>

using namespace std;

int d[100010];

int main()
{
	int n, k;

	cin >> n >> k;

	queue<int> q;
	d[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int head = q.front();
		q.pop();
		if (head == k)
			break;

		if (head > 0 && d[head - 1] == 0) {
			d[head - 1] = d[head] + 1;
			q.push(head - 1);
		}
		if (head < 100000 && d[head + 1] == 0) {
			d[head + 1] = d[head] + 1;
			q.push(head + 1);
		}
		if ((head << 1) <= 100000 && d[head << 1] == 0) {
			d[head << 1] = d[head] + 1;
			q.push(head << 1);
		}
	}

	cout << d[k] - 1;

	return 0;
}