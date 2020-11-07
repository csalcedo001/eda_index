#include <iostream>
#include <fstream>

using namespace std;

struct Record {
	char c[30];
	int i;
	double d;
};

int main() {
	fstream out_file("data/test.dat", ios::binary | ios::out);

	Record r;

	r.c[0] = 'a';
	r.c[1] = '\0';
	r.i = 100;
	r.d = 0.9;

	out_file.write((char *) &r, sizeof(Record));

	out_file.close();
	
	return 0;
}
