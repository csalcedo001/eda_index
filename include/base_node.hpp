#ifndef B_TREE_BASE_NODE_HPP_
#define B_TREE_BASE_NODE_HPP_

#include <array>

namespace eda {

namespace b_tree {

template <typename T, int m, typename Node>
class BaseNode {
public:
	T values_[m];
	Node *children_[m + 1];
	int capacity_;

public:
	BaseNode(void);
};

} // namespace b_tree

} // namespace eda

#include "impl/base_node.ipp"

#endif // B_TREE_BASE_NODE_HPP_
