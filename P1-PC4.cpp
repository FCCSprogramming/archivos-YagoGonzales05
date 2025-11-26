/*AUTOR YAGO GONZALES
PROBLEMA 01*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MESES=12;
const int DIAS_MES=30;
const int TOTAL_DIAS=MESES*DIAS_MES;
const int CAPACIDAD_MAX=700;

 struct Fecha{
     int dia;
     int mes;
 };
 struct Registro{
     Fecha *fecha;
     int pasajeros;
 };

int main() {
srand(time(NULL));
Registro A[TOTAL_DIAS];
Registro* p=A;
int contador=0;
for(int m=1;m<=MESES;m++){
    for(int d=1;d<=DIAS_MES;d++){
        p[contador].fecha= new Fecha;

        p[contador].fecha->dia=d;
        p[contador].fecha->mes=m;
        p[contador].pasajeros=500+rand()%201;
        contador++;
    }
}
cout<<"Dias con 95% de carga"<<endl;
for(int i=0;i<TOTAL_DIAS;i++){
    if(p[i].pasajeros>=0.95*CAPACIDAD_MAX){
        cout<<"Fecha: "<<p[i].fecha->dia<<"/"<<p[i].fecha->mes<<" |Pasajeros: "<<p[i].pasajeros<<endl;
    }
}
for(int i=0;i<TOTAL_DIAS;i++){
    delete p[i].fecha;
}
    return 0;
}
