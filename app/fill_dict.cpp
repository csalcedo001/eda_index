#include <iostream>
#include <fstream>
#include "classes.hpp"

using namespace std;

int main() {
	fstream file("data/diccionario.txt", ios::binary | fstream::out);
	
	char palabra1[50] = "alguien";
	string significado1 = "Designa una o varias personas cuya identidad no se conoce o no se desvela.";
	file.write(palabra1, 50);
	int temp = significado1.size();
	file.write((char*) &temp, sizeof(int));
	file.write(significado1.c_str(), significado1.size());
	
	char palabra2[50] = "compuesto";
	string significado2 = "Que está formado por dos o más elementos.";
	file.write(palabra2, 50);
	temp = significado2.size();
	file.write((char*) &temp, sizeof(int));
	file.write(significado2.c_str(), significado2.size());
	
	char palabra3[50] = "distinguir";
	string significado3 = "Conocer la diferencia que hay de unas cosas a otras.";
	file.write(palabra3, 50);
	temp = significado3.size();
	file.write((char*) &temp, sizeof(int));
	file.write(significado3.c_str(), significado3.size());
	
	file.close();
	
	return 0;
}
