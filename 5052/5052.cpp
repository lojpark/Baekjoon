/*
Hash
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, bool> d;
string str[10010];

int main()
{
	int t;
	int n;
	int i, j;

	cin >> t;
	for (; t >= 1; t--) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> str[i];
			d[str[i]] = true;
		}

		for (i = 1; i <= n; i++) {
			string temp = "";
			for (j = 0; j < str[i].length() - 1; j++) {
				temp += str[i][j];
				if (d[temp]) {
					j = -1;
					break;
				}
			}
			if (j == -1) {
				break;
			}
		}
		if (j == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}

		d.clear();
	}

	return 0;
}