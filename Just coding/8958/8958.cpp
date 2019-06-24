#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string a;
		int score = 0, combo = 0;
		cin >> a;
		for (int j = 0; j < (int)a.size(); j++) {
			if (a[j] == 'O')
				score += (++combo);
			else
				combo = 0;
		}
		cout << score << endl;
	}

	return 0;
}