#ifndef FECHA_H
#define FECHA_H

#include <time.h>

class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha(int, int, int);
        Fecha();
        void setDia(int d){if (d>0&&d<32)_dia=d;else{_dia=0;}}
        void setMes(int m){if (m>0&&m<13)_mes=m;else{_mes=0;}}
        void setAnio(int a){if (a>1900)_anio=a;else{_anio=0;}}
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}

};

#endif // FECHA_H
