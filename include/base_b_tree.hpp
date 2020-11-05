#ifndef B_TREE_BASE_B_TREE_HPP_
#define B_TREE_BASE_B_TREE_HPP_

#include "base_node.hpp"

namespace eda {

namespace b_tree {

template <typename T, int m, typename Node>
class BaseBTree {
public:
	enum State {
		NODE_OVERFLOW,
		NODE_UNDERFLOW,
		NODE_OK
	};

protected:
	Node *head_;

public:
	BaseBTree();
	~BaseBTree();

	void insert(T);
	bool exists(T);
	void remove(T);
	int size();
	void print();

protected:
	State insert(Node *, T);
	Node *divide(Node *&);
	void insert_within(Node *, int, T, Node *);
	int child_key(Node *, T);
	void print(Node *, int level);
	void kill(Node *);
};

} // namespace b_tree

} // namespace eda

#include "impl/base_b_tree.ipp"

#endif // B_TREE_B_TREE_HPP_
