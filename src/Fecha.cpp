#include "Fecha.h"

#include "Proveedor.h"
#include "Impuesto.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "rlutil.h"
#include <cstdio>
#include <conio.h>

using namespace std;

using namespace rlutil;

Fecha::Fecha()
{
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
    cin>>d;
    cout<<"MES"<<endl;
    cin>>m;
    cout<<"AÑO"<<endl;
    cin>>a;

}
