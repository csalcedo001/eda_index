#ifndef INDEX_RAM_RECORD_HPP_
#define INDEX_RAM_RECORD_HPP_

#include "base_node.hpp"
#include "persona.hpp"

namespace eda {

namespace index {

class RamRecord : public b_tree::BaseNode<Persona, RamRecord> {
    char key[10];
    long pdir;
    long offset;  
};

} // namespace index

} // namespace eda

#endif // INDEX_RAM_RECORD_HPP_
