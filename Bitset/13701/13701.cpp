#include <stdio.h>
#include <bitset>

using namespace std;

bitset<33554433> bit;

int main()
{
	int num;

	bit.reset();

	while (scanf("%d", &num) != EOF) {
		if (bit[num]) continue;
		bit.set(num, true);
		printf("%d ", num);
	}
}