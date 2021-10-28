#ifndef PLANDECUENTAS_H
#define PLANDECUENTAS_H

#include "Funciones.h"

class PlanDeCuentas
{
    private:
        int _cuentaContable;
        char _descripcionCuenta[30];
        bool _estado;

    public:
        void setCuentaContable(int);
        void setDescripcionCuenta(const char*);
        void setEstadoPlan(bool);
        int getCuentaContable();
        const char *getDescripcionCuenta();
        bool getEstadoPlan();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        bool leerDeDisco(int);
        void listarPlanDeCuentas();

};

#endif // PLANDECUENTAS_H
