#ifndef PLANDECUENTAS_H
#define PLANDECUENTAS_H


class PlanDeCuentas
{
    private:
        int _cuentaContable;
        char _descripcionCuenta[30];

    public:
        PlanDeCuentas();
        void setCuentaContable(int);
        void setDescripcionCuenta(char*);
        int getCuentaContable();
        char *getDescripcionCuenta();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        bool leerEnDisco();

};

#endif // PLANDECUENTAS_H
