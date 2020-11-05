#ifndef B_TREE_LEAF_HPP_
#define B_TREE_LEAF_HPP_

#include "node.hpp"

namespace eda {

template <int m, typename T>
class Leaf : public BTree<m, T>::Node {
public:
	Leaf();
};

} // namespace eda

#include "impl/leaf.ipp"

#endif // B_TREE_LEAF_HPP_
