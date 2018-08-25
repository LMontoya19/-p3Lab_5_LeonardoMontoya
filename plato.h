#ifndef PLATO_H
#define PLATO_H
#include <vector>
#include <string>
#include "ingrediente.h"
using std::vector;
using std::string;
class plato{
    private:
        string nombre;
        string origen;
        int sabor;
        int cocinado;
        int precio;
        double valoracionp;
        vector<ingrediente*> ingredientes;
        vector<int> cantidad;
    public:
        plato(string,string,int,int);
        vector<ingrediente*>& getIngredientes();
        vector<int>& getCantidad();
        string getNombre();
        void setValoracion(int);
        int getValoracion();
        void setCocinado();
        int getCocinado();
        int getprecio();
};
#endif