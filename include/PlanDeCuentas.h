#ifndef PLANDECUENTAS_H
#define PLANDECUENTAS_H


class PlanDeCuentas
{
    private:
        int _cuentaContable;
        char _descripcionCuenta[30];
        bool _estado;

    public:
        PlanDeCuentas();
        void setCuentaContable(int);
        void setDescripcionCuenta(char*);
        void setEstado(bool);
        int getCuentaContable();
        char *getDescripcionCuenta();
        bool getEstadoPlan();
        void cargar();
        void mostrar();
        void listarPlanDeCuentas();
        bool guardarEnDisco();
        bool leerDeDisco(int);

};

#endif // PLANDECUENTAS_H
