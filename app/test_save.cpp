#include <iostream>
#include <fstream>

#include "persona.hpp"

using namespace std;

int main()
{
  fstream file("data/data.dat", ios::binary | fstream::out);
  eda::index::Persona P("0001","Cesar Madera"," Su casa");
  eda::index::Persona Q("0002","Ariana Villegas"," otro lado");
  eda::index::Persona R("0003","Fabrazio Garcia"," Por ahi");

  P.Write(file);
  Q.Write(file);
  R.Write(file);
  //Persona P[3];
  
  // file.read((char*)P, sizeof(Persona)*3);
  // P[0].Print();
  // P[1].Print();
  // P[2].Print();
 
  return 1;
}
