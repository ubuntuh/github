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
	}
};
void deleteTree(Node *node)
{
	if (node == NIL)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}
struct Tree {
	Node *root;
	~Tree() {
		// puts("Destructing Tree");
		deleteTree(root);
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

Node *find(Node *node, int key)
{
	if (node == NIL)
		return NIL;
	if (node->key == key)
		return node;
	if (key < node->key)
		return find(node->left, key);
	else
		return find(node->right, key);
}

void find(Tree *T, int key)
{
	if (find(T->root, key) != NIL)
		puts("yes");
	else
		puts("no");
}

void deleteNode(Tree *T, int key)
{
	Node *z = find(T->root, key);
	if (z == NIL)
		return;
	int numChildren = 0;
	if (z->left != NIL)
		++numChildren;
	if (z->right != NIL)
		++numChildren;
	if (numChildren == 0) {
		Node *parent = z->p;
		if (parent == NIL)
			T->root == NIL;
		else if (parent->left == z)
			parent->left = NIL;
		else
			parent->right = NIL;
		delete z;
	} else if (numChildren == 1) {
		Node *parent = z->p;
		Node *child;
		if (z->left != NIL)
			child = z->left;
		else
			child = z->right;
		if (parent == NIL)
			T->root = child;
		else if (parent->left == z) {
			parent->left = child;
			child->p = parent;
		} else {
			parent->right = child;
			child->p = parent;
		}
		delete z;
	} else {
		Node *y = z->right;	// z よりも後ろにあって最小のノードを y に求めます。
		while (y->left != NIL) {
			y = y->left;
		}
		z->key = y->key;	// y の値を z にコピーして y を削除します。
		Node *parent = y->p;
		Node *child = y->right;	// y に左の子はありえません。
		if (child == NIL) {
			if (parent->left == y)
				parent->left = NIL;
			else if (parent->right == y)
				parent->right = NIL;
		} else {
			if (parent->left == y) {
				parent->left = child;
				child->p = parent;
			} else {
				parent->right = child;
				child->p = parent;
			}
		}
		delete y;
	}
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
			else if (operatorStr[0] == 'f')
				find(T, operand);
			else
				deleteNode(T, operand);
		}
	}
	delete T;
	delete NIL;
	return 0;
}
