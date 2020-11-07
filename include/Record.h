#ifndef BTREE_CON_PAGINACION_CLION_RECORD_H
#define BTREE_CON_PAGINACION_CLION_RECORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

struct Record {
    std::string word;
    std::string definition;

    Record() = default;
    Record(std::string word, std::string definition) : word{word}, definition{definition} {}
    Record(long pos) {
        std::fstream file("data.dat");
        file.seekg(pos);
        std::string line;
        getline(file, line);
        std::stringstream ss(line);
        std::string token;
        getline(ss, token, '|');
        word = token;
        getline(ss, token, '|');
        definition = token;
    }

};

#endif //BTREE_CON_PAGINACION_CLION_RECORD_H
