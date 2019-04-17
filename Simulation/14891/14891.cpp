#include <iostream>

using namespace std;

int wheel[5];
int turn[5];

int main()
{
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			wheel[i] <<= 1;
			char flag;
			cin >> flag;
			if (flag == '1')
				wheel[i] += 1;
		}
	}

	int k;
	cin >> k;

	for (; k >= 1; k--) {
		for (int i = 1; i <= 4; i++) {
			turn[i] = 0;
		}

		int number, flag;
		cin >> number >> flag;

		turn[number] = flag;

		for (int i = number + 1; i <= 4; i++) {
			if (((wheel[i] >> 1) & 1) ^ ((wheel[i - 1] >> 5) & 1))
				turn[i] = turn[i - 1] * -1;
			else
				break;
		}
		for (int i = number - 1; i >= 1; i--) {
			if (((wheel[i] >> 5) & 1) ^ ((wheel[i + 1] >> 1) & 1))
				turn[i] = turn[i + 1] * -1;
			else
				break;
		}

		for (int i = 1; i <= 4; i++) {
			int temp = 0;
			// Clockwise
			if (turn[i] == 1) {
				temp = wheel[i] & 1;
				wheel[i] >>= 1;
				wheel[i] += temp << 7;
			}

			// Counter-Clockwise
			else if (turn[i] == -1) {
				temp = (wheel[i] >> 7) & 1;
				wheel[i] <<= 1;
				wheel[i] += temp;
				wheel[i] &= 255;
			}
		}
	}

	int answer = 0;
	for (int i = 4; i >= 1; i--) {
		answer <<= 1;
		answer += (wheel[i] >> 7) & 1;
	}

	cout << answer;
	return 0;
}