#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a, stack;
		bool is_vps = true;
		cin >> a;
		for (int j = 0; j < (int)a.size(); j++) {
			if (a[j] == '(')
				stack.push_back('(');
			else {
				if (stack.empty()) {
					is_vps = false;
					break;
				}
				stack.pop_back();
			}
		}
		if (!stack.empty())
			is_vps = false;
		if (is_vps)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}