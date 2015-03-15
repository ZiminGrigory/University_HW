#pragma once
#include <queue>

using namespace std;

template <typename T>
class Tree
{
public:
	Tree()
	{}
	~Tree() {
		destr(head);
	}

	void add(T elem) {
		if (!head) {
			head = new Node{elem, nullptr, nullptr};
			return;
		}

		auto p = head;
		while (true) {
			if (p->value < elem && !p->left) {
				p->left = new Node{elem, nullptr, nullptr};
				return;
			}

			if (p->value >= elem && !p->right) {
				p->right = new Node{elem, nullptr, nullptr};
				return;
			}

			p = p->value >= elem ? p->right : p->left;
		}
	}

	void printTree() {
		cout << "Tree\n";
		queue<Node *> q;
		if (head)
			q.push(head);

		while (!q.empty()) {
			Node *v = q.front();
			q.pop();
			cout << " " << v->value;
			if (v->left)
				q.push(v->left);
			if (v->right)
				q.push(v->right);
		}
	}

private:

	struct Node
	{
		Node(T elem, Node *l, Node *r) : value(elem), left(l), right(r){}
		T value;
		Node *left = nullptr;
		Node *right = nullptr;
	};

	void destr(Node *v) {
		if (v->left)
			destr(v->left);
		if (v->right)
			destr(v->right);
		delete v;
	}

	Node *head = nullptr;
};

