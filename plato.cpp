#include "plato.h"
#include <string>
using std::string;
plato::plato(string pnombre, string porigen, int psabor, int pcantidad)
{
    nombre = pnombre;
    origen = porigen;
    sabor = psabor;
    precio = pcantidad;
    valoracionp = 0;
    cocinado = 1;
}

vector<ingrediente *> &plato::getIngredientes()
{
    return ingredientes;
}
vector<int> &plato::getCantidad()
{
    return cantidad;
}

string plato::getNombre()
{
    return nombre;
}

void plato ::setValoracion(int pValoracion)
{
    valoracionp += pValoracion;
}
int plato::getValoracion()
{
    return valoracionp / cocinado;
}
void plato ::setCocinado()
{
    cocinado++;
}
int plato ::getCocinado()
{
    return cocinado;
}
int plato:: getprecio(){
    return precio;
}