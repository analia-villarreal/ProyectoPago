#include "Funciones.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Reportes.h"
#include "Mensaje.h"


using namespace std;

using namespace rlutil;

void marco_comprobante(int x, int y, int ancho, int alto )
{

    setBackgroundColor(BLACK);
    //cls();
    setColor(LIGHTCYAN);
    int i;
    for(i=x; i<=x+ancho; i++)
    {
        setlocale(LC_ALL, "C");
        gotoxy(i,y);
        printf("\xdB");
        gotoxy(i,y+alto);
        printf("\xdB");
    }


    for(i=y; i<=y+alto; i++)
    {
        setlocale(LC_ALL, "C");
        gotoxy(x,i);
        printf("\xdB");
        gotoxy(x+ancho,i);
        printf("\xdB");


    }

}

const char* buscarNombreMedioDePago(int medio)
{
    MediosDePagos reg;

    int pos;

    pos=buscarPosMP(medio);

    reg.leerDeDisco(pos);

    cout<<" - "<<reg.getDescripcionMP()<<endl;

}

const char* buscarNombreCuentaContable(int cuentaCont)
{
    PlanDeCuentas reg;

    int pos;

    pos=buscarPosCuenta(cuentaCont);

    reg.leerDeDisco(pos);


   cout<<" - "<<reg.getDescripcionCuenta()<<endl;

}
int buscarPosMP(int medio)
{
    MediosDePagos reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( medio == reg.getIdMedioPago())
        {
            return i;
        }
        i++;
    }
    return -1;

}


int buscarPosCuenta(int cuentaCont)
{
    PlanDeCuentas reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( cuentaCont == reg.getCuentaContable())
        {
            return i;
        }
        i++;
    }
    return -1;

}
int contarProveedores()
{
    int bytes, cr;
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Proveedor);
    fclose(p);
    return cr;
}

int buscarPosProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return i;
        }
        i++;
    }
    return -1;

}

bool buscarProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return true;
        }
        i++;
    }
    return false;
}

char* buscarNombProv2(int idProveedor)
{
    Proveedor reg;

    int pos;

    pos=buscarPosProveedor(idProveedor);

    reg.leerDeDisco(pos);

   return reg.getRazonSocial();

}

void buscarNombProveedor(int idProveedor)
{
    Proveedor reg;

    int pos;

    pos=buscarPosProveedor(idProveedor);

    reg.leerDeDisco(pos);

   cout<<""<<reg.getRazonSocial()<<endl;


}

void buscarFacturasProveedor(int idProveedor)
{

    Comprobante reg;

    int i = 0;

    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
          if(reg.getNumFac()!=0){

                gotoxy(12,21+i);cout<<reg.getPV()<<"-"<< reg.getNumFac()<<"="<<reg.getImporteTotal();
                cout<<endl;
            }
        }

        i++;
    }

}

bool sinRepetidos(int n, int vec[])
{

    for(int i=0; i<5; i++)
    {
        if(n == vec[i])
        {
            return true;
        }

    }
    return false;
}

bool sinRepetidosDiez(int n, int vec[])
{

    for(int i=0; i<10; i++)
    {
        if(n == vec[i])
        {
            return true;
        }

    }
    return false;
}

void rand_proveedores()
{

    int vecNum[5]= {};

    int prov;

    prov = contarProveedores();

    int i=0;
    int valor;

    while(i<5)
    {

        valor=rand()%prov+1;
        while(sinRepetidos(valor,vecNum)==false)
        {
            vecNum[i]=valor;
            i++;
        }

    }

    for(int j=0; j<5; j++)
    {
        Proveedor reg;

        int pos;

        pos=buscarPosProveedor(vecNum[j]);

        reg.leerDeDisco(pos);
        rlutil::locate(4, 26+j);
        cout<<vecNum[j]<<" - "<< reg.getRazonSocial()<<" - "<<reg.getCategoria()<<endl;

    }

}

void rand_proveedoresOP()
{

    int vecNum[10]= {};

    int prov;

    prov = contarProveedores();

    int i=0;
    int valor;

    while(i<10)
    {

        valor=rand()%prov+1;
        while(sinRepetidosDiez(valor,vecNum)==false)
        {
            vecNum[i]=valor;
            i++;
        }

    }

    for(int j=0; j<10; j++)
    {
        Proveedor reg;

        int pos;

        pos=buscarPosProveedor(vecNum[j]);

        reg.leerDeDisco(pos);
        rlutil::locate(85,26+j);
        cout<<vecNum[j]<<" - "<< reg.getRazonSocial()<<" - "<<reg.getCategoria()<<endl;

    }

}

void listarProveedores()
{
    int i=0;
    Proveedor reg;

    cout << left;
    cout << setw(8)  << "CODIGO";
    cout << setw(25) << "NOMBRE";
    cout << setw(30) << "CATEGORIA"<<endl;

    while(reg.leerDeDisco(i))
    {

        reg.mostrar();
        cout << endl;
        i++;
    }

}

bool soloNumeros(const char *cadena)
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if(!(cadena[i] >= '0' && cadena[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
}

float buscarAlicuota(int idProveedor)
{

    Proveedor reg;

    int pos;

    int ali;

    pos=buscarPosProveedor(idProveedor);


    while(reg.leerDeDisco(pos))
    {


        int  ali=reg.getIVA();

        if(ali=1)
        {
            return 21;
        }
        if(ali=2)
        {
            return 10.5;
        }
        if(ali=3)
        {
            return 0;
        }

    }
    return -1;
}

void menuComprobante()
{


    Comprobante reg;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU COMPROBANTES-----" << endl;
        gotoxy(40,6);cout << "---------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA COMPROBANTE"         << endl;
        gotoxy(40,8);cout << "2. BAJA COMPROBANTE"         << endl;
        gotoxy(40,9);cout << "3. LISTAR COMPROBANTES"      << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: - " << endl;
        gotoxy(40,12);cout << "---------------------------" << endl;
        gotoxy(40,13);cout<<" > ";cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            int tipoComp;
            gotoxy(40,5);cout << "Factura: 1  Nota de Crédito: 2"<< endl;
            gotoxy(40,6);cout<<" > ";cin>>tipoComp;
            system("cls");
            reg.cargar(tipoComp);
            if(reg.getEstado()==true)
            {
                if(reg.guardarEnDisco()==true)
                {
                   gotoxy(4,41);cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                   resetColor();
                }
                else
                {
                    gotoxy(4,41);cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                    resetColor();
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            gotoxy(4,42);system("pause");
            break;
        case 2:
        //BAJA COMPROBANTE;
        case 3:
            reg.listarComprobantes();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuProveedor()
{
    Proveedor reg1;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU PROVEEDOR--------" << endl;
        gotoxy(40,6);cout << "---------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA PROVEEDOR          " << endl;
        gotoxy(40,8);cout << "2. BAJA PROVEEDOR          " << endl;
        gotoxy(40,9);cout << "3. LISTAR PROVEDORES       " << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: - " << endl;
        gotoxy(40,12);cout << "---------------------------" << endl;
        gotoxy(40,13);cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            reg1.cargar();
            if(reg1.getEstadoProv()==true)
            {
                if(reg1.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
            bajaProveedor();
        case 3:
            listarProveedores();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuPlandeCuentas()
{
    PlanDeCuentas obj;
    int opc;
    while(true)
    {
        system("cls");
        cout << "--------MENU PLAN DE CUENTAS--------" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. ALTA CUENTA CONTABLE             " << endl;
        cout << "2. DESACTIVAR CUENTA CONTABLE       " << endl;
        cout << "3. LISTAR PLAN DE CUENTAS           " << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL         " << endl;
        cout << "- SELECCIONE UNA OPCION: -          " << endl;
        cout << "------------------------------------" << endl;
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            obj.cargar();
            if(obj.getEstadoPlan()==true)
            {
                if(obj.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
        //BAJA PROVEEDOR;
        case 3:
            obj.listarPlanDeCuentas();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void menuOP()
{
    OrdenDePago regis;
    int opc;
    while(true)
    {
        system("cls");
        gotoxy(40,5);cout << "-----MENU ORDENES DE PAGO -----" << endl;
        gotoxy(40,6);cout << "---------------------------" << endl;
        gotoxy(40,7);cout << "1. ALTA "         << endl;
        gotoxy(40,8);cout << "2. BAJA "         << endl;
        gotoxy(40,9);cout << "3. LISTAR "      << endl;
        gotoxy(40,10);cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        gotoxy(40,11);cout << "- SELECCIONE UNA OPCION: - " << endl;
        gotoxy(40,12);cout << "---------------------------" << endl;
        gotoxy(40,13);cout<<" > ";cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            int tipoOP;
            gotoxy(40,5);cout << "REALIZAR PAGOS "<< endl;
            gotoxy(40,5);cout << "PAGOS VARIOS : 1  PAGO A PROVEEDOR: 2"<< endl;
            gotoxy(40,6);cout<<" > ";cin>>tipoOP;
            system("cls");
            regis.cargar(tipoOP);
            if(regis.getEstadoOP()==true)
            {
                if(regis.guardarEnDisco()==true)
                {
                   gotoxy(4,41);cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                   resetColor();
                }
                else
                {
                    gotoxy(4,41);cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                    resetColor();
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            gotoxy(4,42);system("pause");
            break;
        case 2:
        //BAJA COMPROBANTE;
            MediosDePagos obj;
        case 3:obj.listarMediosDePagos();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}

void bajaProveedor()
{
    Proveedor reg;
    int i=0, idProv, opc;
    char *cpynombre;
    FILE *p;
    p = fopen("proveedores.dat", "rb+");

    if(p == nullptr){
        cout << "EL ARCHIVO NO SE ABRIO CORRECTAMENTE.";
        return;

    }
    cout << "------------- LISTA DE PROVEEDORES A DAR DE BAJA ---------------" << endl;
    while(reg.leerDeDisco(i)){
        if(reg.getEstadoProv() == true){
            cout << "----------------" << endl;
            reg.mostrar();
            cout << "----------------" << endl;
            i++;
        }
    }

    cout << "SELECCIONE EL CODIGO DEL PROVEEDOR QUE DESEE DAR DE BAJA: ";

    cin >> idProv;

    while(idProv > contarProveedores()){
        cout << "EL CODIGO DEL PROVEEDOR NO EXISTE." << endl;
        cout << "POR FAVOR INGRESE OTRO CODIGO DE PROVEEDOR: ";
        cin >> idProv;
    }

    if(buscarProveedor(idProv) == true){
        int tam=strlen(buscarNombProv2(idProv));
        cpynombre=new char[tam+1];
        strcpy(cpynombre,buscarNombProv2(idProv));

        cout << "EL PROVEEDOR " << cpynombre << " SE ESTA POR DAR DE BAJA. ESTA SEGURO? ";
        cout << " 1 / SI  --  2 / NO" << endl;
        cin >> opc;
            if(opc == 1){
                fseek(p,sizeof(Proveedor)*idProv,0);
                reg.setEstadoProv(false);
                cout << "EL PROVEEDOR SE DIO DE BAJA" << endl;
                system("pause");
            }
            else return;
    }
    delete cpynombre;

    fclose(p);
}
