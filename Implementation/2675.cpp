#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n;
		string a;
		cin >> n >> a;
		for (int i = 0; i < (int)a.size(); i++) {
			for (int j = 1; j <= n; j++)
				cout << a[i];
		}
		cout << endl;
	}

	return 0;
}