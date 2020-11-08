#include <iostream>

#include "b_tree.hpp"
#include "char_array.hpp"

using namespace std;

int main() {

    BTree<CharArray<45>, 3> bt;

    //------------ READ ---------------
    fstream file("data/data/data.dat");

    string line;

    long pos = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, '\t');

        CharArray<45> temp(token);

        bt.insert(temp, pos);
        pos = file.tellg();
    }

    //----------- SEARCH --------------
	string query;

	cin >> query;

    CharArray<45> temp(query);
    Record found = bt.search(temp);

    cout << found.word << " : " << found.definition << endl;

    return 0;
}
