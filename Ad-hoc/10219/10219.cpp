#include <cstdio>

int n, m;
char a[12][12];

int main()
{
	int t;
	
	scanf("%d", &t);
	
	for (; t >= 1; t--) {
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= n; i++) {
			getchar();
			for (int j = 1; j <= m; j++) {
				scanf("%c", &a[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%c", a[i][m - j + 1]);
			}
			printf("\n");
		}
	}

	return 0;
}