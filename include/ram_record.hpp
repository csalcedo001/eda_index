#ifndef INDEX_RAM_RECORD_HPP_
#define INDEX_RAM_RECORD_HPP_

#include "base_node.hpp"
#include "persona.hpp"

namespace eda {

namespace index {

template <int m>
class RamRecord : public b_tree::BaseNode<Persona, m, RamRecord<m> > {
    char key[10];
    long pdir;
    long offset;  
};

} // namespace index

} // namespace eda

#endif // INDEX_RAM_RECORD_HPP_
