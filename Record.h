#ifndef BTREE_CON_PAGINACION_CLION_RECORD_H
#define BTREE_CON_PAGINACION_CLION_RECORD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

struct Record {

    string word;
    string definition;

    Record() = default;

    Record(string word, string definition) : word{word}, definition{definition} {}

    Record(long pos) {
        fstream file("data.dat");
        file.seekg(pos);
        string line;
        getline(file, line);
        stringstream ss(line);
        string token;
        getline(ss, token, '|');
        word = token;
        getline(ss, token, '|');
        definition = token;
    }

};

#endif //BTREE_CON_PAGINACION_CLION_RECORD_H