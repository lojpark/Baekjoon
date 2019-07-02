#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int count[26] = { 0 };
	cin >> a;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] > 'Z')
			a[i] -= 'a' - 'A';
		count[a[i] - 'A']++;
	}

	int max = -1, index = 0;
	for (int i = 0; i < 26; i++) {
		if (max < count[i]) {
			max = count[i];
			index = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == count[i] && i != index) {
			cout << "?";
			return 0;
		}
	}
	cout << (char)(index + 'A');
	return 0;
}