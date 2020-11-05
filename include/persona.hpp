#ifndef INDEX_PERSONA_HPP_
#define INDEX_PERSONA_HPP_

#include <fstream>

namespace eda {

namespace index {

class Persona
{
    private:
       char key[10];
       char Nombre[100];
       char Direccion[100];
       
    public:
       Persona()
       {
         key[0]=0;
         Nombre[0]=0;
         Direccion[0]=0;
       }

       Persona(std::string k, std::string n, std::string d)
       {
         strcpy(key,k.c_str());
         strcpy(Nombre,n.c_str()) ;
         strcpy(Direccion ,d.c_str());
       }
      
       void Write(std::fstream & file)
       {
            file.write((char*)this, sizeof(Persona));
       }      

       void Read(std::fstream & file)
       {
            file.read((char*)this, sizeof(Persona));
       } 

       void Print()
       {
           std::cout<<key<<"  "<<Nombre<<" "<<Direccion<<std::endl;
       }     

};

} // namespace index

} // namespace eda

#endif // INDEX_PERSONA_HPP_
