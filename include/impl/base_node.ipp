#ifndef B_TREE_NODE_IPP_
#define B_TREE_NODE_IPP_

#include "base_node.hpp"

#include "base_b_tree.hpp"

namespace eda {

namespace b_tree {

template <typename T, int m, typename Node>
BaseNode<T, m, Node>::BaseNode() {
	for (int i = 0; i < m; i++) {
		this->children_[i] = nullptr;
	}
}

} // namespace b_tree

} // namespace eda

#endif // B_TREE_NODE_IPP_
