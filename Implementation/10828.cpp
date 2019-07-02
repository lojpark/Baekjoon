#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	vector<int> a;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int number;
			cin >> number;
			a.push_back(number);
		}
		else if (order == "pop") {
			if (a.empty())
				cout << "-1" << endl;
			else {
				cout << a.back() << endl;
				a.pop_back();
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
		else if (order == "top") {
			if (a.empty())
				cout << "-1" << endl;
			else
				cout << a.back() << endl;
		}
	}

	return 0;
}