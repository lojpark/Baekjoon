/*
DFS
*/
#include <iostream>
#include <math.h>

int height, n, leafFrom;
int plusSum;
struct Tree {
	int value;
	int leftEdge;
	int rightEdge;
}t[2500000];

int dfsFindMax(int node) {
	if (node >= leafFrom) {
		return 0;
	}

	int left = 0, right = 0;

	left = dfsFindMax(node*2) + t[node].leftEdge;
	right = dfsFindMax(node*2 + 1) + t[node].rightEdge;

	if (left > right) t[node].value = left;
	else t[node].value = right;

	return t[node].value;
}

void dfsPlusSum(int node) {
	if (node >= leafFrom) {
		return;
	}
	plusSum += t[node].value - (t[node].leftEdge + t[node*2].value);
	dfsPlusSum(node*2);
	plusSum += t[node].value - (t[node].rightEdge + t[node*2 + 1].value);
	dfsPlusSum(node*2 + 1);
}

int main()
{
	int i, temp = 0;
	int sum = 0;

	std::cin >> height;
	
	leafFrom = (int)pow(2, height);
	n = (int)pow(2, (height + 1)) - 1;
	for (i = 1; i < leafFrom; i++) {
		std::cin >> temp;
		t[i].leftEdge = temp;
		std::cin >> temp;
		t[i].rightEdge = temp;
		sum += t[i].leftEdge + t[i].rightEdge;
	}

	dfsFindMax(1);
	dfsPlusSum(1);

	std::cout << sum + plusSum;

	return 0;
}