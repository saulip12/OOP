#include <iostream>
#include <string>
using namespace std;

class Persona
{
public:
 string nombre;
 int edad;

 void saludar(){
 cout<<"Hola,soy "<<nombre<<" y tengo "<<edad<<" años.\n";
 }
};
int main(){
 Persona p1;
    p1.nombre= "Maria Paula";
    p1.edad = 18;
    p1.saludar();
 Persona p2;
    p2.nombre="Lina";
    p2.edad= 30;
    p2.saludar();
 Persona p3;
    p3.nombre="Camilo";
    p3.edad=19;
    p3.saludar();
return 0;
}

