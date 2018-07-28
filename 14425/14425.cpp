#include <iostream>
#include <string>

using namespace std;

int n, m;
char dic[10010][510];
char word[10010][510];

struct Trie
{
	Trie *next[26];
	bool finish;

	Trie()
	{
		for (int i = 0; i < 26; i++) next[i] = NULL;
		finish = false;
	}

	void insert(char *key)
	{
		if ((*key) == '\0') {
			finish = true;
			return;
		}

		int nextKey = (*key) - 'a';

		if (next[nextKey] == NULL) {
			next[nextKey] = new Trie();
		}
		next[nextKey]->insert(key + 1);
	}

	bool isExist(char *key)
	{
		if ((*key) == '\0') {
			if (finish) return true;
			return false;
		}

		int nextKey = (*key) - 'a';

		if (next[nextKey] == NULL) {
			return false;
		}
		return next[nextKey]->isExist(key + 1);
	}
};

int main()
{
	int i;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> dic[i];
	}
	for (i = 1; i <= m; i++) {
		cin >> word[i];
	}

	Trie *root = new Trie();
	for (i = 1; i <= n; i++) {
		root->insert(dic[i]);
	}

	int cnt = 0;
	for (i = 1; i <= m; i++) {
		if (root->isExist(word[i])) cnt++;
	}

	cout << cnt;

	return 0;
}