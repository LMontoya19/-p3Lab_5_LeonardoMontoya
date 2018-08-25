#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "plato.h"
using std::string;
#include <vector>
using std::vector;
class cliente{
    private:
        vector<plato*> platos;
        int evaluacion;
        double gastado;

    public:
        cliente();
        vector<plato*>& getPlatos();
        int getEvaluacion();
        void setEvaluacion(int);
        double getDinero();
        void setDinero(int);

};
#endif