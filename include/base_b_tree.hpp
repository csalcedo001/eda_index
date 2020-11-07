#ifndef B_TREE_BASE_B_TREE_HPP_
#define B_TREE_BASE_B_TREE_HPP_

#include "base_node.hpp"

namespace eda {

namespace b_tree {

template <typename K, int m, typename Node>
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

	void insert(K);
	bool exists(K);
	void remove(K);
	int size();
	void print();

protected:
	State insert(Node *, K);
	Node *divide(Node *&);
	void insert_within(Node *, int, K, Node *);
	int child_key(Node *, K);
	void print(Node *, int level);
	void kill(Node *);
};

} // namespace b_tree

} // namespace eda

#include "impl/base_b_tree.ipp"

#endif // B_TREE_B_TREE_HPP_
