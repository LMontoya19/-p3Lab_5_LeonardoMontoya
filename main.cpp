#include "plato.h"
#include "ingrediente.h"
#include "cliente.h"
#include <math.h>
#include <time.h> 
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char resp = 's';
    vector<cliente*> ventas;
    vector<ingrediente*> ingredientes;
    vector<plato*> platos;
    vector<int> llenado;
    while (resp == 's')
    {
        cout<<"1)BODEGA" << endl;
        cout<<"2)Restaurante"<<endl;
        cout<<"3)Salir"<<endl;
        cout<<"Ingrese su opcion: ";
        char opcion;
        cin>>opcion;
        switch(opcion){
            case '1':{
                cout<<"***Bodega***"<<endl;
                cout<<"1)Listar Ingredientes:"<<endl;
                cout<<"2)Crear Ingrediente:"<<endl;
                cout<<"3)Listar platos:"<<endl;
                cout<<"4)Crear Plato:"<<endl;
                cout<<"5)Listar veces que se ha llenado ingredientes en bodega "<<endl;
                cout<<"6)Ventas"<<endl;
                char opcionbodega;
                opcionbodega=0;
                cout<<"Ingrese su opcion: "<<endl;
                cin>>opcionbodega;
                if(opcionbodega=='1'){
                    for(int i = 0;i<ingredientes.size();i++){
                        cout<<"Ingrediente: "<<ingredientes[i]->getNombre()<<" Tipo: "<<ingredientes[i]->getTipo()<<" Cantidad:"<<ingredientes[i]->getCantidad()<<endl;
                    };
                }else if(opcionbodega=='2'){
                    string nombre;
                    string tipo;
                    int sabor;
                    int cantidad;
                    int duracion;
                    cout<<"Ingrese nombre de ingrediente: "<<endl;
                    cin>>nombre;
                    char validartipo='s';
                    while(validartipo=='s'){
                        cout<<"Ingrese tipo: "<<endl;
                        cin>>tipo;
                        if(tipo.compare("lacteo")==0||tipo.compare("vegetales")==0||tipo.compare("frutas")==0||tipo.compare("otros")==0){
                            validartipo='n';
                        }else{
                            cout<<"Opcion no valida"<<endl;
                        };
                    }
                    cout<<"Ingrese cantidad de sabor"<<endl;
                    cin>>sabor;
                    cout<<"Ingrese cantidad en inventario"<<endl;
                    cin>>cantidad;
                    cout<<"Ingrese duracion"<<endl;
                    cin>>duracion;
                    ingrediente* ningrediente = new ingrediente(nombre,tipo,sabor,cantidad,duracion);
                    ingredientes.push_back(ningrediente);
                    llenado.push_back(0);
                }else if(opcionbodega=='3'){
                    
                    for(int i = 0; i < platos.size(); i++)
                    {
                        cout<<platos[i]->getNombre()<<endl;
                    }
                    
                }else if(opcionbodega=='4'){
                    string nombreplato;
                    string origen;
                    int precio;
                    cout<<"Ingrese nombre del plato: "<<endl;
                    cin>>nombreplato;
                    cout<<"Ingrese origen del plato"<<endl;
                    cin>>origen;
                    cout<<"Ingrese precio: "<<endl;
                    cin>>precio;
                    plato* platocreado = new plato(nombreplato,origen,0,precio);
                    char opcrearplato = 's';
                    while(opcrearplato=='s'){
                        for(int i = 0;i<ingredientes.size();i++){
                            cout<<i<<ingredientes[i]->getNombre()<<endl;
                        }
                        cout<<"Ingrese -1 para dejar de añadir ingredientes"<<endl;
                        cout<<"Que ingrediente desea añadir(numero)"<<endl;
                        int ingredienteelegido;
                        cin>>ingredienteelegido;
                        if(ingredienteelegido==-1){
                            opcrearplato='n';
                        }else if(ingredienteelegido<ingredientes.size()){
                            platocreado->getIngredientes().push_back(ingredientes[ingredienteelegido]);
                            cout<<"Ingrese cantidad de ingredientes necesitada"<<endl;
                            int inecesitado;
                            cin>>inecesitado;
                            platocreado->getCantidad().push_back(inecesitado);

                        }else{
                            cout<<"Opcion no valida"<<endl;
                        }
                    }
                    platos.push_back(platocreado);
                }else if(opcionbodega=='5'){
                    for(int i = 0;i<ingredientes.size();i++){
                        cout<<ingredientes[i]->getNombre()<<" : "<<llenado[i];
                    }
                }else if(opcionbodega=='6'){
                    for(int i = 0;i<ventas.size();i++){
                        cout<<ventas[i]->getEvaluacion()<<ventas[i]->getDinero()<<endl;;
                    };
                }
                else{
                    cout<<"Opcion no valida"<<endl;
                };
                break;
            }
            case '2':{
                cliente* cl = new cliente();
                cout<<"Restaurante"<<endl;
                char oprestaurante='s';
                while(oprestaurante=='s'){
                  cout<<"Lista de platos: "<<endl;
                  for(int i = 0;i<platos.size();i++){
                    cout<<i<<") "<<platos[i]->getNombre()<<endl;
                  };
                int platoelegido;
                platoelegido=-1;
                while(platoelegido<0||platoelegido>platos.size()-1){
                    cout<<"Ingrese numero de plato que quiere: "<<endl;
                    cin>>platoelegido;
                    if(platoelegido<0||platoelegido>platos.size()-1){
                        cout<<"Opcion no valida"<<endl;
                    };
                }
                cout<<"Elaborando: "<<platos[platoelegido]->getNombre()<<endl;
                for(int i = 0;i<platos[platoelegido]->getIngredientes().size();i++){
                    for(int j = 0;j<ingredientes.size();i++){
                        if(ingredientes[j]->getNombre()==platos[platoelegido]->getIngredientes()[i]->getNombre()){
                            while(ingredientes[j]->getCantidad()<platos[platoelegido]->getCantidad()[i]){
                                int iSecret;
                                srand(time(NULL));
                                /* generate secret number between 1 and 10: */
                                iSecret = rand() % 3+ 1;
                                ingredientes[j]->setCantidad(ingredientes[j]->getCantidad());
                                llenado[j] += 1;
                            };
                        }
                    };
                };
                platos[platoelegido]->setCocinado();
                cout<<"Ingrese valoracion de 1 a 5 del plato"<<endl;
                int val;
                cin>>val;
                platos[platoelegido]->setValoracion(val);
                cl->setDinero(platos[platoelegido]->getprecio());
                cl->setEvaluacion(val);
                cl->getPlatos().push_back(platos[platoelegido]);
                cout<<"Desea otro plato(s/n)"<<endl;
                cin>>oprestaurante;
                };
                ventas.push_back(cl);
                break;
            }
            case '3':{
                resp = 'n'; 
            }
            default:
                cout<<"Opcion no valida"<<endl;
        }
    };
    return 0;
}
