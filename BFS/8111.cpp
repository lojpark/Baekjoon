#include <iostream>
#include <queue>

using namespace std;

int n;

struct Data {
	int number;
	int path[100], n;
};

queue<Data> q;
bool visit[1000100];

int main()
{
	int t;

	cin >> t;
	for (; t > 0; t--) {
		queue<Data> empty;
		q.swap(empty);

		cin >> n;
		for (int i = 0; i < n; i++)
			visit[i] = false;

		Data head, tail;
		tail.number = 1;
		tail.path[0] = 1;
		tail.n = 1;
		q.push(tail);

		while (!q.empty()) {
			head = q.front();

			if (head.number % n == 0)
				break;

			q.pop();

			tail = head;

			tail.number = (head.number * 10) % n;
			if (!visit[tail.number]) {
				tail.path[tail.n++] = 0;
				visit[tail.number] = true;
				q.push(tail);
				tail.n--;
			}

			tail.number = (head.number * 10 + 1) % n;
			if (!visit[tail.number]) {
				tail.path[tail.n++] = 1;
				visit[tail.number] = true;
				q.push(tail);
			}
		}

		if (!q.empty()) {
			for (int i = 0; i < head.n; i++)
				cout << head.path[i];
		}
		else
			cout << "BRAK";
		cout << endl;
	}

	return 0;
}