#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <string>
using std::string;
class ingrediente{
        private:
            string nombre;
            string tipo;
            int sabor;
            int duracion;
            int cantidad;
        public:
            ingrediente(string,string,int,int,int); 
            void setNombre(string);
            string getNombre();
            void setTipo(string);
            string getTipo();
            void setSabor(int);
            int getSabor();
            void setDuracion(int);
            int getDuracion();
            int getCantidad();
            void setCantidad(int);           
}; 
#endif