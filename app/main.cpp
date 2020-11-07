#include <iostream>

#include "BTree.h"

using namespace std;

template <int T>
struct CharArray {
    CharArray() = default;
    CharArray(const string& temp) { strcpy(data, temp.c_str()); }
    CharArray(char in[T]) { memcpy(data, in, T); }

    char& operator[](unsigned int idx) { return data[idx]; }
    char data[T];

    bool operator < (const CharArray<T>& idx) const {
        string lhd(data);
        string rhd(idx.data);
        return lhd < rhd;
    }
    bool operator == (const CharArray<T>& idx) const {
        string lhd(data);
        string rhd(idx.data);
        return lhd == rhd;
    }
};

int main() {

    BTree<CharArray<45>, 3> bt;

    //------------ READ ---------------
    fstream file("data/data/data.dat");
    string line;
    long pos = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, '|');
        CharArray<45> temp(token);
        bt.insert(temp, pos);
        pos = file.tellg();
    }

    //----------- SEARCH --------------
    CharArray<45> temp("face");
    Record found = bt.search(temp);
    cout << found.word << " : " << found.definition << endl;

    return 0;
}
