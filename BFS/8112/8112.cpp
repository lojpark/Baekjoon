#include <iostream>
#include <queue>

int n;

struct Data {
	int to;
	char value;
};

std::queue<int> q;
Data path[1000100];
bool visit[1000100];

void print_path(int cur) {
	if (cur == -1)
		return;
	print_path(path[cur].to);
	std::cout << path[cur].value;
}

int main()
{
	int t;

	std::cin >> t;
	for (; t > 0; t--) {
		std::queue<int> empty;
		q.swap(empty);

		std::cin >> n;
		for (int i = 0; i < n; i++)
			visit[i] = false;

		int head, tail;
		visit[1] = true;
		path[1].to = -1;
		path[1].value = '1';
		q.push(1);

		while (!q.empty()) {
			head = q.front();

			if (head % n == 0)
				break;

			q.pop();

			tail = (head * 10) % n;
			if (!visit[tail]) {
				visit[tail] = true;
				path[tail].to = head;
				path[tail].value = '0';
				q.push(tail);
			}

			tail = (head * 10 + 1) % n;
			if (!visit[tail]) {
				visit[tail] = true;
				path[tail].to = head;
				path[tail].value = '1';
				q.push(tail);
			}
		}

		if (!q.empty())
			print_path(head);
		else
			std::cout << "BRAK";
		std::cout << "\n";
	}

	return 0;
}