#ifndef B_TREE_BASE_B_TREE_IPP_
#define B_TREE_BASE_B_TREE_IPP_

#include "base_b_tree.hpp"

#include "base_node.hpp"

namespace eda {

namespace b_tree {

template <typename K, int m, typename Node>
BaseBTree<K, m, Node>::BaseBTree() : head_(nullptr) {}

template <typename K, int m, typename Node>
BaseBTree<K, m, Node>::~BaseBTree() {
	this->kill(this->head_);
}

template <typename K, int m, typename Node>
void BaseBTree<K, m, Node>::print() {
	this->print(this->head_, 0);
}

template <typename K, int m, typename Node>
void BaseBTree<K, m, Node>::insert(K value) {
	if (this->head_ == nullptr) {
		this->head_ = new Node;

		this->head_->values_[0] = value;
		this->head_->children_[0] = nullptr;
		this->head_->children_[1] = nullptr;

		this->head_->capacity_ = 2;
	}
	else if (this->insert(this->head_, value) == NODE_OVERFLOW) {
		Node *right_child = this->head_;
		Node *left_child = this->divide(right_child);

		this->head_ = new Node;

		this->head_->values_[0] = left_child->values_[left_child->capacity_ - 1];
		this->head_->children_[0] = left_child;
		this->head_->children_[1] = right_child;
		
		this->head_->capacity_ = 2;
	}
}

template <typename K, int m, typename Node>
typename BaseBTree<K, m, Node>::State BaseBTree<K, m, Node>::insert(Node *node, K value) {
	int child_index = this->child_key(node, value);
	int value_index = std::min(child_index, m - 1);

	Node *child = node->children_[child_index];

	if (child == nullptr) {
		this->insert_within(node, child_index, value, nullptr);
	}
	else if (this->insert(child, value) == NODE_OVERFLOW) {
		Node *new_child = this->divide(node->children_[child_index]);
		this->insert_within(node, child_index, new_child->values_[new_child->capacity_ - 1], new_child);
	}

	return node->capacity_ == m + 1 ? NODE_OVERFLOW : NODE_OK;
}

template <typename K, int m, typename Node>
Node *BaseBTree<K, m, Node>::divide(Node *&right_node) {
	int mid = (m - 1) / 2;

	Node *left_node = right_node;
	right_node = new Node;

	for (int i = mid + 1; i < m; i++) {
		right_node->values_[i - mid - 1] = left_node->values_[i];
		right_node->children_[i - mid - 1] = left_node->children_[i];
	}

	right_node->children_[m - mid - 1] = left_node->children_[m];

	left_node->capacity_ = mid + 1;
	right_node->capacity_ = m - mid;

	return left_node;
}

template <typename K, int m, typename Node>
void BaseBTree<K, m, Node>::insert_within(Node *node, int child_index, K value, Node *child) {
	for (int i = node->capacity_; i > std::max(child_index, 1); i--) {
		node->children_[i] = node->children_[i - 1];
		node->values_[i - 1] = node->values_[i - 2];
	}

	if (child_index == 0) {
		node->children_[1] = node->children_[0];
	}

	int value_index = std::min(child_index, m - 1);

	node->children_[child_index] = child;
	node->values_[value_index] = value;

	node->capacity_++;
}

template <typename K, int m, typename Node>
int BaseBTree<K, m, Node>::child_key(Node *node, K value) {
	for (int i = 0; i < node->capacity_ - 1; i++) {
		if (value < node->values_[i]) {
			return i;
		}
	}

	return node->capacity_ - 1;
}

template <typename K, int m, typename Node>
void BaseBTree<K, m, Node>::print(Node *node, int level) {
	if (node != nullptr) {
		this->print(node->children_[0], level + 1);

		for (int i = 1; i < node->capacity_; i++) {
			for (int j = 0; j < level; j++) {
				std::cout << "    ";
			}
			std::cout << node->values_[i - 1] << std::endl;

			this->print(node->children_[i], level + 1);
		}
	}
}

template <typename K, int m, typename Node>
void BaseBTree<K, m, Node>::kill(Node *node) {
	if (node != nullptr) {
		for (int i = 0; i < node->capacity_; i++) {
			this->kill(node->children_[i]);
		}

		delete node;
	}
}

} // namespace b_tree

} // namespace eda

#endif // B_TREE_BASE_B_TREE_IPP_
