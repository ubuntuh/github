// Accepted.
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
		if (operatorStr[0] == 'i') {
			int operand;
			scanf("%d", &operand);
			insert(T, operand);
		} else {
			print(T);
		}
	}
	delete T;
	delete NIL;
	return 0;
}
