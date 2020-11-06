#include <iostream>

#include "classes.hpp"

using namespace std;

int main() {
	Pagina p;
	string query;
	
	p.Read();
	
	cout << "Query: ";
	
	cin >> query;
	
	Entry *result = p.Find(query);
	
	if (result == nullptr) {
		cout << "No entry \"" << query << '\"' << endl;
	}
	else {
		cout << result->significado << endl;
	}
	
	return 0;
}
