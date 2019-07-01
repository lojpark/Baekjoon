#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int n;
	queue<int> a;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int number;
			cin >> number;
			a.push(number);
		}
		else if (order == "pop") {
			if (a.empty())
				cout << "-1" << endl;
			else {
				cout << a.front() << endl;
				a.pop();
			}
		}
		else if (order == "size")
			cout << a.size() << endl;
		else if (order == "empty") {
			if (a.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (order == "front") {
			if (a.empty())
				cout << "-1" << endl;
			else
				cout << a.front() << endl;
		}
		else if (order == "back") {
			if (a.empty())
				cout << "-1" << endl;
			else
				cout << a.back() << endl;
		}
	}

	return 0;
}