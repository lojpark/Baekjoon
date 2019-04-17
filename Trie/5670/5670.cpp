#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int n, m;
char dic[100010][510];

struct Trie
{
	vector<Trie*> next;
	char key;
	bool finish;

	Trie(char key)
	{
		this->key = key;
		this->finish = false;
	}

	void insert(char *key)
	{
		if ((*key) == '\0') {
			finish = true;
			return;
		}

		int i;
		for (i = 0; i < next.size(); i++) {
			if (next[i]->key == *key) break;
		}

		if (i == next.size()) {
			next.push_back(new Trie(*key));
		}
		next[i]->insert(key + 1);
	}

	int counting(char *key, int index, int count)
	{
		if ((*key) == '\0') {
			return count;
		}

		int i;
		for (i = 0; i < next.size(); i++) {
			if (next[i]->key == *key) break;
		}

		if (next.size() == 1 && index != 0) {
			if (finish) count++;

			return next[i]->counting(key + 1, index + 1, count);
		}
		else return next[i]->counting(key + 1, index + 1, count + 1);
	}
};

int main()
{
	int i;
	Trie *root;
	int cnt = 0;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++) {
			scanf("%s", &dic[i]);
		}

		root = new Trie(0);
		for (i = 1; i <= n; i++) {
			root->insert(dic[i]);
		}

		cnt = 0;
		for (i = 1; i <= n; i++) {
			cnt += root->counting(dic[i], 0, 0);
		}

		printf("%.2lf\n", cnt / (double)n);

		delete root;
	}

	return 0;
}