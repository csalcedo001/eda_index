#ifndef B_TREE_B_TREE_HPP_
#define B_TREE_B_TREE_HPP_

#include "base_b_tree.hpp"
#include "base_node.hpp"
#include "node.hpp"

namespace eda {

namespace b_tree {

template <typename T, int m>
class BTree : public BaseBTree<T, m, Node<T, m> > { };

} // namespace b_tree

} // namespace eda

#endif // B_TREE_B_TREE_HPP_
