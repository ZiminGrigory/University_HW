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

	void add(const T &elem) {
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

	void printTree() const {
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

	void printTreeWithDepths() const {
		cout << "Tree\n";
		queue<pair<Node *, int> > q;
		if (head)
			q.push(make_pair(head, 0));

		while (!q.empty()) {
			pair<Node *, int> p = q.front();
			Node *v = p.first;
			int depth = p.second;
			q.pop();
			cout << " " << v->value << "depth = " << depth << "; ";
			if (v->left)
				q.push(make_pair(v->left, depth + 1));
			if (v->right)
				q.push(make_pair(v->right, depth + 1));
		}
	}

	bool hasElBetween20_30() const {
		return hasElBetween20_30(head);
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
		destr(v->left);
		destr(v->right);
		delete v;
	}

	bool hasElBetween20_30(const Node * const v) const{
		if (!v) {
			return false;
		}

		if (v->value >= 20 && v->value <= 30) {
			return true;
		}

		if (v->value > 30) {
			return hasElBetween20_30(v->right);
		}

		if (v->value < 20) {
			return hasElBetween20_30(v->left);
		}
	}

	Node *head = nullptr;
};

