#include "ingrediente.h"
#include <string>
using std::string;
void ingrediente::setNombre(string pNombre)
{
    nombre = pNombre;
}

string ingrediente::getNombre()
{
    return nombre;
}

void ingrediente::setTipo(string ptipo){
   tipo=ptipo; 
}

string ingrediente::getTipo(){
    return tipo;
}
void ingrediente::setSabor(int psabor){
    sabor = psabor;
}
int ingrediente::getSabor(){
    return sabor;
}
void ingrediente::setDuracion(int pduracion){
    duracion= pduracion;
}
int ingrediente::getCantidad(){
    return cantidad;
}
void ingrediente::setCantidad(int xcantidad){
    cantidad=xcantidad;
}
ingrediente::ingrediente(string pnombre,string ptipo,int psabor,int pcantidad,int pduracion){
    nombre=pnombre;
    tipo = ptipo;
    sabor = psabor;
    duracion = pduracion;
    cantidad = pcantidad;
}
