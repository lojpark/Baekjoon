#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;

	cin >> a;

	for (int i = 0; i < (int)a.size(); i++) {
		cout << a[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	return 0;
}