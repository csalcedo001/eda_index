#include <iostream>

#include "b_tree.hpp"
#include "char_array.hpp"

using namespace std;

int main() {
	string dictionary;

	cin >> dictionary;

	b_tree_setup(dictionary);

    //------------ READ ---------------
    fstream file(data_path);

	if (!file.is_open()) {
		cerr << "No dictionary " << dictionary << endl;
		return 1;
	}

    BTree<CharArray<45>, 3> bt;

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
	cout << disk_calls << endl;

    return 0;
}
