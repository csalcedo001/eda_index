#include <iostream>

#include "b_tree.hpp"

int main()
{
    eda::b_tree::BTree<int, 3> btree;
    
    btree.insert(1);
    btree.insert(4);
    btree.insert(5);
    btree.insert(1);
    btree.insert(-1);
    btree.insert(8);
    btree.insert(9);
    btree.insert(2);
    btree.insert(7);

	btree.print();

    return 0;
}
