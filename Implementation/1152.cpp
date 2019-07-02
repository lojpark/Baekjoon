#include <stdio.h>

int main()
{
	char input;
	int count = 0;
	bool first = true, last = false;
	while (scanf("%c", &input)) {
		if (input == NULL || input == '\n')
			break;
		if (input == ' ') {
			if (first)
				first = false;
			else
				count++;
			last = true;
		}
		else
			first = last = false;
	}
	if (last)
		count--;

	printf("%d", count + 1);

	return 0;
}