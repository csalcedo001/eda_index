#ifndef INDEX_RAM_INDEX_HPP_
#define INDEX_RAM_INDEX_HPP_

#include "base_b_tree.hpp"
#include "ram_record.hpp"
#include "persona.hpp"
#include "functions.hpp"

namespace eda {

namespace index {

class Index : public b_tree::BTree<Persona, Index> {
private:
	std::list<RamRecord> records_;
	char data_filename_[100];

public:
	Index(std::string data_filename) {
		strcpy(this->data_filename_, data_filename.c_str());
	} 
	void Execute() {
		std::ifstream file(this->data_filename_, std::ios::binary);

		Record record;

		while (file.peek() != EOF) {
			record.pdir = file.tellg();
			record.offset = sizeof(Persona);
			file.read((char *) record.key, 10);

			this->records_.push_back(record);

			file.seekg(200);
		}
	}

	// Guarda en Disco el archico index.dat 
	void Write() {
		std::string index_filename;
		std::ofstream file(this->data_filename_, std::ios::binary);

		for (auto record : this->records_) {
			file.write((char *) &record, sizeof(Record));
		}
	}
	void Read() {
		std::ifstream file(this->data_filename_, std::ios::binary); 

		Record record;

		while (file.peek() != EOF) {
			file.read((char *) &record, sizeof(Record));

			this->records_.push_back(record);
		}
	}

	// Debe buscar la clava en la lista
	// mostrar la información de esa persona en el archivo de Personas. 
	// void Find(char * key) {
	// 	for (auto record : this->records_) {
	// 		if 
	// }
};

} // namespace index

} // namespace eda

#endif // INDEX_RAM_INDEX_HPP_
