#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;
bool d[10000];

struct Data {
	int value;
	vector<char> log;
};

queue<Data> q;

int main()
{
	int t;
	cin >> t;

	for (; t > 0; t--) {
		for (int i = 0; i < 10000; i++)
			d[i] = false;
		while (!q.empty())
			q.pop();
		cin >> a >> b;

		Data head, tail;
		tail.value = a;
		d[tail.value] = true;
		q.push(tail);
		while (!q.empty()) {
			head = q.front();
			tail.log.clear();
			for (int i = 0; i < head.log.size(); i++)
				tail.log.push_back(head.log[i]);
			q.pop();

			// D
			tail.value = (head.value * 2) % 10000;
			if (!d[tail.value]) {
				d[tail.value] = true;
				tail.log.push_back('D');
				if (tail.value == b)
					break;
				q.push(tail);
				tail.log.pop_back();
			}

			// S
			tail.value = head.value - 1;
			if (tail.value < 0)
				tail.value = 9999;
			if (!d[tail.value]) {
				d[tail.value] = true;
				tail.log.push_back('S');
				if (tail.value == b)
					break;
				q.push(tail);
				tail.log.pop_back();
			}

			// L
			tail.value = ((head.value / 100) % 10) * 1000 + ((head.value / 10) % 10) * 100 + (head.value % 10) * 10 + (head.value / 1000);
			if (!d[tail.value]) {
				d[tail.value] = true;
				tail.log.push_back('L');
				if (tail.value == b)
					break;
				q.push(tail);
				tail.log.pop_back();
			}

			// R
			tail.value = (head.value % 10) * 1000 + (head.value / 1000) * 100 + ((head.value / 100) % 10) * 10 + ((head.value / 10) % 10);
			if (!d[tail.value]) {
				d[tail.value] = true;
				tail.log.push_back('R');
				if (tail.value == b)
					break;
				q.push(tail);
				tail.log.pop_back();
			}
		}

		for (int i = 0; i < tail.log.size(); i++)
			cout << tail.log[i];
		cout << endl;
	}
	return 0;
}