/*
Binary search(Parametric search)
*/
#include <stdio.h>

long long n, k;

inline long long min(long long a, long long b) {
	return(a<b?a:b);
}

long long thNumber(long long num, bool *isPossible) {
	long long i;
	long long count = 0;

	for (i = 1; i <= n; i++) {
		count += min(num/i, n);
		if (num%i == 0 && num <= i*n) {
			(*isPossible) = true;
		}
	}

	return count;
}

int main()
{
	scanf_s("%lld%lld",&n,&k);

	long long left, right, mid;
	long long th = 0;
	bool isPossible = false;

	left = 1;
	right = k;
	mid = (left + right)/2;
	while (true) {
		isPossible = false;
		th = thNumber(mid, &isPossible);

		if (th == k) {
			if (isPossible) {
				break;
			}
			else {
				right = mid;
				mid = (left + right)/2;
			}
		}
		else if (left == mid) {
			if (isPossible && th > k) {
				break;
			}
			else {
				left++;
				mid = (left + right)/2;
			}
		}
		else if (th < k) {
			left = mid;
			mid = (left + right)/2;
		}
		else {
			right = mid;
			mid = (left + right)/2;
		}
	}

	printf("%lld\n", mid);
	return 0;
}