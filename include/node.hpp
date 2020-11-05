#ifndef B_TREE_NODE_HPP_
#define B_TREE_NODE_HPP_

#include <array>

#include "base_node.hpp"

namespace eda {

namespace b_tree {

template <typename T, int m>
class Node : public BaseNode<T, m, Node<T, m> > { };

} // namespace b_tree

} // namespace eda

#endif // B_TREE_NODE_HPP_
