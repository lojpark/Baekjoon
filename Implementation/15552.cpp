#include <stdio.h>

int main()
{
	int t;
	int a, b;
	scanf("%d", &t);
	for (; t >= 1; t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}