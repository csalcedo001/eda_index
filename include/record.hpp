#ifndef INDEX_RECORD_HPP_
#define INDEX_RECORD_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

struct Record {
    std::string word;
    std::string definition;

    Record() = default;

    Record(std::string word, std::string definition) :
		word{word},
		definition{definition}
	{ }

    Record(long pos) {
        std::fstream file(data_path);
        std::string line;

        file.seekg(pos);
        getline(file, line);

        std::stringstream ss(line);
        std::string token;

        getline(ss, token, '\t');
        word = token;
        getline(ss, token, '\t');
        definition = token;
    }
};

#endif // INDEX_RECORD_HPP_
