#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class node {
private:
	int key;
	node* left;
	node* right;
public:
	node(int key = 0) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
	~node() {
		delete left;
		delete right;
	}
	int getk() {
		return key;
	}
	void setk(int k) {
		key = k;
	}
	node* getl() {
		return left;
	}
	node* getr() {
		return right;
	}
	void setl(int key) {
		left = new node(key);
	}
	void setr(int key) {
		right = new node(key);
	}
};
class tree {
	node* root;
public:
	tree() {
		root = new node;
	}
	~tree() {
		delete root;
	}
	node* getr() {
		return root;
	}
	void insert(node* a, int k) {
		if (a->getk() == 0) {
			a->setk(k);
		}
		else if (k < a->getk()) {
			if (a->getl() == NULL)
				a->setl(k);
			else
				insert(a->getl(), k);
		}
		else {
			if (a->getr() == NULL)
				a->setr(k);
			else
				insert(a->getr(), k);
		}
	}
	void postorder(node* r) {
		if (r == NULL)
			return;
		postorder(r->getl());
		postorder(r->getr());
		cout << r->getk() << endl;
	}
};
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	tree* t = new tree();

	while (scanf("%d", &n) != EOF) {
		t->insert(t->getr(), n);
	}

	t->postorder(t->getr());
	
	delete t;
	return 0;
}