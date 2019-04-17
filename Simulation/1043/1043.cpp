#include <iostream>
#include <bitset>

using namespace std;

int n, t, m;
bitset<51> truth;
struct Party
{
	int n;
	int people[51];
	bool canLie;
}party[51];

int main()
{
	cin >> n >> m >> t;

	int answer = m;
	int input;
	truth.reset();
	for (int i = 1; i <= t; i++) {
		cin >> input;
		truth[input] = true;
	}
	for (int i = 1; i <= m; i++) {
		cin >> party[i].n;
		party[i].canLie = true;
		for (int j = 1; j <= party[i].n; j++) {
			cin >> party[i].people[j];
			if (truth[party[i].people[j]]) {
				party[i].canLie = false;
			}
		}
		if (!party[i].canLie) answer--;
	}

	bool chk = false;
	while (true) {
		for (int i = 1; i <= m; i++) {
			if (!party[i].canLie) {
				for (int j = 1; j <= party[i].n; j++) {
					truth[party[i].people[j]] = true;
				}
			}
		}

		chk = false;
		for (int i = 1; i <= m; i++) {
			if (party[i].canLie) {
				for (int j = 1; j <= party[i].n; j++) {
					if (truth[party[i].people[j]]) {
						party[i].canLie = false;
						answer--;
						chk = true;
						break;
					}
				}
			}
		}

		if (!chk)
			break;
	}

	cout << answer;

	return 0;
}