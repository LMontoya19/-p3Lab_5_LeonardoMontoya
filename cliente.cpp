#include "cliente.h"
#include <vector>
using std::vector;

cliente::cliente(){
    evaluacion=0;
    gastado=0;
}

vector<plato*>& cliente::getPlatos(){
    return platos;
}

int cliente::getEvaluacion(){
    return evaluacion/platos.size();
}
void cliente::setEvaluacion(int evaluado){
    evaluacion+= evaluado;

}

double cliente::getDinero(){
    return gastado;
}

void cliente::setDinero(int x){
    gastado+=x;

}