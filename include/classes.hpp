#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define WORD_SIZE 50
#define WORDS_PER_PAGE 3

struct Entry {
	char palabra[WORD_SIZE];
	std::string significado;
	
	friend std::ostream &operator<<(std::ostream &os, Entry &entry) {
		os << entry.palabra << entry.significado;
		return os;
	}
	
	friend std::istream &operator>>(std::istream &is, Entry &entry) {
		is.read((char*) &entry.palabra, sizeof(entry.palabra));
		
		int size;
		is.read((char*) &size, sizeof(int));
		
		entry.significado.resize(size);
		
		is.read((char*) &entry.significado[0], size);
		
		return is;
	}
};

struct Record {
	char palabra[WORD_SIZE];
	unsigned int puntero;
	
	friend std::ostream &operator<<(std::ostream &os, Record &record) {
		os << record.palabra << record.puntero;
		return os;
	}
	
	friend std::istream &operator>>(std::istream &is, Record &record) {
		is.read((char*) &record.palabra, sizeof(record.palabra));
		
		is.read((char*) &record.puntero, sizeof(record.puntero));
		
		return is;
	}
};

class Pagina {
private:
	Entry palabras[WORDS_PER_PAGE];
	unsigned int p_Inicio;
	unsigned int p_Final;

public:
	Pagina() {}
	
	void Read() {
		std::fstream file("data/diccionario.txt", std::ios::binary | std::ios::in | std::ios::out);
		for (int i = 0; i < WORDS_PER_PAGE; i++) {
			file >> palabras[i];
		}
	}
	
	Entry *Find(std::string key) {
		int left = 0, right = WORDS_PER_PAGE - 1, mid;
		
		while (left < right) {
			mid = (left + right) / 2;
			
			if (strcmp(palabras[mid].palabra, key.c_str()) == 0) return &palabras[mid];
			
			if (strcmp(key.c_str(), palabras[mid].palabra) > 0) {
			    left = mid + 1;
			}
			else {
			    right = mid - 1;
			}
		}
		
		if (strcmp(palabras[mid].palabra, key.c_str()) == 0) return &palabras[mid];
		
		return nullptr;
	}
	
	void Print() {
		for (int i = 0; i < WORDS_PER_PAGE; i++) {
			std::cout << palabras[i].palabra << ": " << palabras[i].significado << std::endl;
		}
	}
};

class Index {
private:
	std::string filename;

public:
	Index(std::string filename): filename(filename) {}
	
	void Generar() {
	std::fstream file("data/indice.txt", std::ios::binary | std::ios::in | std::ios::out);
		while (!file.eof()) {
			
		}
	}
};
