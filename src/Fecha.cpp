#include "Fecha.h"

#include "Proveedor.h"
#include "Impuesto.h"
#include "Impuesto.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

Fecha::Fecha()
{
    /// FECHA DEL SISTEMA
    time_t tiempobase;
    struct tm *timeinfo;
    char aux_fec[11];
    time(&tiempobase);
    timeinfo=localtime(&tiempobase);
    strftime(aux_fec,11,"%d/%m/%Y",timeinfo);

    _dia=((int)aux_fec[0]-48)*10+((int)aux_fec[1]-48);
    _mes=((int)aux_fec[3]-48)*10+((int)aux_fec[4]-48);
    _anio=((int)aux_fec[6]-48)*1000+((int)aux_fec[7]-48)*100+((int)aux_fec[8]-48)*10+((int)aux_fec[9]-48);
}


Fecha::Fecha(int d, int m, int a)
{
    if (d<0 || d>31 || m<0 || m>12 || a<0)
    {
        _dia=0;
        _mes=0;
        _anio=0;
    }
    else
    {
        _dia=d;
        _mes=m;
        _anio=a;
    }
}


void Fecha::cargar(){

    int d,m,a;

    cout<<"DIA"<<endl;
    cout<<"MES"<<endl;
    cout<<"AÑO"<<endl;

    cin>>d;
    cin>>m;
    cin>>a;
}
