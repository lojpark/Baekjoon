/*
Priority queue
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, d;
struct Data{
	int st, ed;
}a[100010];

bool cmp(Data q, Data qq) {
	return q.ed < qq.ed;
}

struct qcmp {
	bool operator()(Data q, Data qq) {
		return q.st > qq.st;
	}
};

int main()
{
	int i, tmp;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i].st >> a[i].ed;
		if (a[i].st > a[i].ed) {
			tmp = a[i].st;
			a[i].st = a[i].ed;
			a[i].ed = tmp;
		}
	}
	cin >> d;

	sort(a + 1, a + 1 + n, cmp);

	priority_queue<Data, vector<Data>, qcmp> q;

	int l = 0, cnt = 0, max = 0;
	for (i = 1; i <= n; i++) {
		if (a[i].ed - a[i].st > d) continue;

		if (l <= a[i].st && a[i].ed <= l + d) {
			q.push(a[i]);
		}
		else {
			l = a[i].ed - d;
			while (q.size() > 0) {
				if (q.top().st < l)
					q.pop();
				else
					break;
			}
			q.push(a[i]);
		}
		if (max < q.size())
			max = q.size();
	}

	cout << max;

	return 0;
}