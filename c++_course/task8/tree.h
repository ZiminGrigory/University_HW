#pragma once
#include <queue>
#include <functional>

using std::queue;
using std::function;
using std::cout;

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

	template<typename T1, typename F>
	friend void ForEach(Tree<T1> *t, F f);

public: // can not write private or ptotected; get error ... is private ... within this context, but it's compiler's bug google says
		// but may be i'm wrong
	struct Node
	{
		Node(T elem, Node *l, Node *r) : value(elem), left(l), right(r){}
		T value;
		Node *left = nullptr;
		Node *right = nullptr;
	};

	void destr(Node *v) {
		if (v) {
			destr(v->left);
			destr(v->right);
		}
		delete v;
	}

	Node *head = nullptr;
};

template <typename T, typename F>
void ForEach(Tree<T> *t, F f) {
	queue<typename Tree<T>::Node *> q;
	if (t->head)
		q.push(t->head);

	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		f(v->value);
		if (v->left)
			q.push(v->left);
		if (v->right)
			q.push(v->right);
	}
}
