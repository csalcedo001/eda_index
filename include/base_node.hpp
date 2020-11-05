#ifndef B_TREE_BASE_NODE_HPP_
#define B_TREE_BASE_NODE_HPP_

#include <array>

namespace eda {

namespace b_tree {

template <typename T, int m, typename Node>
class BaseNode {
public:
	std::array<T, m> values_;
	std::array<Node *, m + 1> children_;
	int capacity_;

public:
	BaseNode(void);
};

} // namespace b_tree

} // namespace eda

#include "impl/base_node.ipp"

#endif // B_TREE_BASE_NODE_HPP_
