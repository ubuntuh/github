// Time Limit Exceeded.
// 4 つのテストのうち入力の多い in4.txt でのみ TLE (Time Limit Exceeded)。
// 二分探索木であることを利用すれば O(log(n)) で find できるところを、総当り法によって O(n) にしたためであると思われる。
#include <cstdio>

struct Node;

Node *NIL;
struct Node {
	Node *p;	// parent.
	Node *left;
	Node *right;
	int key;
	~Node() {
		// printf("Destructing Node. key = %d\n", key);
		if (left != NIL)
			delete left;
		if (right != NIL)
			delete right;
	}
};
struct Tree {
	Node *root;
	~Tree() {
		// puts("Destructing Tree");
		delete root;
	}
};

void insert(Tree *T, Node *z)
{
	Node *y = NIL;	// z の親になるべきノードを y に求めます。
	Node *x = T->root;
	while (x != NIL) {	// 根から葉まで下っていきます。
		y = x;	// 親を設定
		if (z->key < x->key) {
			x = x->left;	// 左の子へ移動
		} else {
			x = x->right;	// 右の子へ移動
		}
	}	// z を挿入すべき位置は確定しました。
	z->p = y;
	if (y == NIL) {	// T が空の場合
		T->root = z;
	} else if (z->key < y->key) {
		y->left = z;	// z を y の左の子にする
	} else {
		y->right = z;	// z を y の右の子にする
	}
}

void insert(Tree *T, int key)
{
	Node *z = new Node();
	z->left = NIL;
	z->right = NIL;
	z->key = key;
	insert(T, z);
}

void printInorder(Node *node)
{
	if (node == NIL)
		return;
	printInorder(node->left);
	printf(" %d", node->key);
	printInorder(node->right);
}

void printPreorder(Node *node)
{
	if (node == NIL)
		return;
	printf(" %d", node->key);
	printPreorder(node->left);
	printPreorder(node->right);
}

void print(Tree *T)
{
	printInorder(T->root);
	puts("");
	printPreorder(T->root);
	puts("");
}

bool find(Node *node, int key)
{
	if (node == NIL)
		return false;
	if (node->key == key)
		return true;
	return find(node->left, key) || find(node->right, key);
}

void find(Tree *T, int key)
{
	if (find(T->root, key))
		puts("yes");
	else
		puts("no");
}

int main(void)
{
	NIL = new Node();
	Tree *T = new Tree();
	T->root = NIL;
	int numInstructions;
	scanf("%d", &numInstructions);
	for (int i = 1; i <= numInstructions; ++i) {
		char operatorStr[7];
		scanf("%s", operatorStr);
		if (operatorStr[0] == 'p') {
			print(T);
		} else {
			int operand;
			scanf("%d", &operand);
			if (operatorStr[0] == 'i')
				insert(T, operand);
			else
				find(T, operand);
		}
	}
	delete T;
	delete NIL;
	return 0;
}
