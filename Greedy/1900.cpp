#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int power[10010], ring[10010];

struct Data {
	int index;
	int value;
}a[10010];

bool cmp(Data t, Data u) {
	return t.value > u.value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> power[i] >> ring[i];
		a[i].index = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int t = power[i] + ring[i] * power[j];
			int s = power[j] + ring[j] * power[i];
			if (t > s) {
				a[i].value++;
			}
			else {
				a[j].value++;
			}
		}
	}

	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1; i <= n; i++) {
		cout << a[i].index << endl;
	}

	return 0;
}