#ifndef INDEX_FUNCTIONS_HPP_
#define INDEX_FUNCTIONS_HPP_

#include <iostream>
#include <string>
#include <fstream>

namespace eda {

namespace index {

void strcpy(const char * p , const char * q);

class Persona
{
    private:
       char key[10];
       char Nombre[100];
       char Direccion[100];
       
    public:
       Persona()
       {
         key[0]=0;
         Nombre[0]=0;
         Direccion[0]=0;
       }

       Persona(std::string k, std::string n, std::string d)
       {
         strcpy(key,k.c_str());
         strcpy(Nombre,n.c_str()) ;
         strcpy(Direccion ,d.c_str());
       }
      
       void Write(std::fstream & file)
       {
            file.write((char*)this, sizeof(Persona));
       }      

       void Read(std::fstream & file)
       {
            file.read((char*)this, sizeof(Persona));
       } 

       void Print()
       {
           std::cout<<key<<"  "<<Nombre<<" "<<Direccion<<std::endl;
       }     

};

struct Record
{
    char key[10];
    long pdir;
    long offset;  
};

class Index
{
private:
	std::list<Record> records_;
	char data_filename_[100];

public:
	Index(string data_filename) {
		strcpy(this->data_filename_, data_filename.c_str());
	} 
	void Execute() {
		std::ifstream file(this->data_filename_, ios::binary);

		Record record;

		while (file.peek() != EOF) {
			record.pdir = file.tellg();
			record.offset = sizeof(Persona);
			file.read((char *) record.key, 10);

			this->records_.push_back(r);

			file.seekg(200);
		}
	}

	// Guarda en Disco el archico index.dat 
	void Write() {
		std::string index_filename;
		std::ofstream file(this->data_filename_, ios::binary);

		for (auto record : this->records_) {
			file.write((char *) &record, sizeof(Record));
		}
	}
	void Read() {
		std::ifstream file(this->data_filename_, ios::binary); 

		Record record;

		while (file.peek() != EOF) {
			file.read((char *) &record, sizeof(Record));

			this->records_.push_back(r);
		}
	}

	// Debe buscar la clava en la lista
	// mostrar la información de esa persona en el archivo de Personas. 
	void Find(char * key) {
		for (auto record : this->records_) {
			if 
	}
};

} // index

} // eda

#endif // INDEX_FUNCTIONS_HPP_
