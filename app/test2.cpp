#include <iostream>
#include <fstream>

using namespace std;

struct Record {
	char c[30];
	int i;
	double d;
};

int main() {
	fstream in_file("data/test.dat", ios::binary | ios::in);

	Record r;

	in_file.read((char *) &r, sizeof(Record));

	in_file.close();

	cout << r.c << ' ' << r.i << ' ' << r.d << endl;
	
	return 0;
}
