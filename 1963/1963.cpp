#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

struct Data {
	int prime;
	int count;
};

bool is_prime(int num)
{
	if (num == 1)
		return false;

	int n = (int) sqrt(num);
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int t;
	int src, dest;
	queue<Data> q;
	bool visit[10000];

	cin >> t;

	for (; t > 0; t--) {
		for (int i = 1000; i <= 9999; i++)
			visit[i] = false;
		queue<Data> empty;
		q.swap(empty);

		cin >> src >> dest;

		Data head, tail;

		tail.prime = src;
		tail.count = 0;
		q.push(tail);

		while (!q.empty()) {
			head = q.front();
			q.pop();

			if (head.prime == dest)
				break;

			tail.count = head.count + 1;
			// 일의 자리
			for (int i = 0; i <= 9; i++) {
				tail.prime = head.prime - (head.prime % 10) + i;
				if (!visit[tail.prime] && is_prime(tail.prime)) {
					visit[tail.prime] = true;
					q.push(tail);
				}
			}

			// 십의 자리
			for (int i = 0; i <= 9; i++) {
				tail.prime = head.prime - (((head.prime / 10) % 10) * 10) + (i * 10);
				if (!visit[tail.prime] && is_prime(tail.prime)) {
					visit[tail.prime] = true;
					q.push(tail);
				}
			}

			// 백의 자리
			for (int i = 0; i <= 9; i++) {
				tail.prime = head.prime - (((head.prime / 100) % 10) * 100) + (i * 100);
				if (!visit[tail.prime] && is_prime(tail.prime)) {
					visit[tail.prime] = true;
					q.push(tail);
				}
			}

			// 천의 자리
			for (int i = 1; i <= 9; i++) {
				tail.prime = head.prime - ((head.prime / 1000) * 1000) + (i * 1000);
				if (!visit[tail.prime] && is_prime(tail.prime)) {
					visit[tail.prime] = true;
					q.push(tail);
				}
			}
		}

		cout << head.count << endl;
	}

	return 0;
}