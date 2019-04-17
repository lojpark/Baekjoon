#include <iostream>
#include <vector>

using namespace std;

int n, m;
char rem[1010][21];
char save[1010][21];
int cnt;

struct Trie
{
	vector<Trie*> next;
	char key;
	bool mustSave;
	bool isWild;

	Trie(char key)
	{
		this->key = key;
		this->mustSave = false;
		this->isWild = false;
	}

	void insert(char *key, bool saveFlag)
	{
		mustSave = saveFlag;

		if ((*key) == '\0') {
			return;
		}

		int i;
		for (i = 0; i < next.size(); i++) {
			if (next[i]->key == *key) break;
		}

		if (i == next.size()) {
			next.push_back(new Trie(*key));
		}
		next[i]->insert(key + 1, saveFlag);
	}

	void removeFile(char *key)
	{
		if ((*key) == '\0' || !mustSave) {
			if (!isWild) {
				isWild = true;
				cnt++;
				return;
			}
			else return;
		}

		int i;
		for (i = 0; i < next.size(); i++) {
			if (next[i]->key == *key) break;
		}

		next[i]->removeFile(key + 1);
	}
};

int main()
{
	int i, t;
	Trie *root;

	cin >> t;

	for (; t > 0; t--) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> rem[i];
		}
		cin >> m;
		for (i = 1; i <= m; i++) {
			cin >> save[i];
		}

		root = new Trie(0);
		for (i = 1; i <= n; i++) {
			root->insert(rem[i], false);
		}
		for (i = 1; i <= m; i++) {
			root->insert(save[i], true);
		}
		cnt = 0;
		for (i = 1; i <= n; i++) {
			root->removeFile(rem[i]);
		}
		cout << cnt << endl;

		delete root;
	}

	return 0;
}