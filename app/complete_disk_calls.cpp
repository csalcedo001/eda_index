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
	int n;

	cin >> n;

	string query;

	auto begin = chrono::steady_clock::now();

	for (int i = 0; i < n; i++) {
		cin >> query;

    	CharArray<45> temp(query);

    	Record found = bt.search(temp);
	}

	auto end = chrono::steady_clock::now();

	cout << n << ' ' << disk_calls << ' ' << chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

    return 0;
}
