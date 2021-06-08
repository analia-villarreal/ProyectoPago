#include "Proveedor.h"
#include "Impuesto.h"



Proveedor::Proveedor()
{
    //ctor
}

void setId(int){

}
void setRazonSocial(char*);
void setCUIT();
void setJuridiccion();
int getId();
char * getRazonSocial(char);
int getCUIT();
int getJuridiccion();
void cargar();
void mostrar();
bool guardarEnDisco();
void guardarEnDisco(int);
bool leerEnDisco();
