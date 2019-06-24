#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int hash[30] = { 0 };

	for (int i = 0; i < 26; i++)
		hash[i] = -1;

	cin >> a;

	for (int i = 0; i < (int)a.size(); i++) {
		if (hash[a[i] - 'a'] == -1)
			hash[a[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << hash[i] << " ";

	return 0;
}