#include <iostream>
#include <fstream>

#include "functions.hpp"

using namespace std;

int main()
{
  fstream file("data/data.dat", ios::binary | fstream::in);

  eda::index::Persona P[3];
  
  file.read((char*)P, sizeof(eda::index::Persona)*3);
  P[0].Print();
  P[1].Print();
  P[2].Print();
 
  return 1;
}


