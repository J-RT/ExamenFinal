#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

struct datoViajero {
    int numPasaporte;
    string nombreViajero;
    string nacionalidad;
    string lugarIngreso;
    string fechaSalida;
    bool verificacion=false;
};

datoViajero datosViajeros[100];

int cantidadCandidatos = 0;

void registrarViajeros () {
    int opcion;
    do {
    cout << "Digite el numero de pasaporte\n";
    cin >> datosViajeros[0].numPasaporte;
    cout << "Digite el nombre del viajero\n";
    cin >> datosViajeros[0].nombreViajero;
    cout << "Digite la nacionalidad del viajero\n";
    cin >> datosViajeros[0].nacionalidad;
    cantidadCandidatos++;
    cout << "\n";
    cout << "0)Registrar mas viajeros\n1)Salir\n";
    cin >> opcion;
    cout << "\n";
    }while (opcion != 1) ;
}
void ingresoSalida() {
    int numPasaporte,i,ubicacion,opcion,opc;
    bool verificacion;
    do {
    cout << "Digite el numero de pasaporte\n";
    cin >> numPasaporte;
    for (i=0;i<=100;i++){
            if (datosViajeros[i].numPasaporte == numPasaporte){
            datosViajeros[i].verificacion = true;
            verificacion = datosViajeros[i].verificacion;
            ubicacion = i;
            }
    }
    if (verificacion == true){
            cout << "0) Para registrar lugar de ingreso\n";
            cout << "1) Para registrar fecha salida\n";
            cin >> opc;
            cout << "\n";
            switch(opc) {
  case 0:
      cout << "Digite lugar de ingreso\n";
            cin >> datosViajeros[ubicacion].lugarIngreso;
            cout << "Registrado con exito\n\n";
    break;
  case 1:
      cout << "Digite fecha salida\n";
            cin >> datosViajeros[ubicacion].fechaSalida;
            cout << "Registrado con exito\n\n";
    break;
}

    } else {
        cout << "Numero de pasaporte no valido, primero debe registrar al viajero\n";

    }
    cout << "0)Registrar EoS\n1)Salir\n";
    cin >> opcion;
    cout << "\n";
    }while (opcion != 1) ;
}

void borrarRegistro() {
      int numPasaporte,ubicacion,i;
      bool verificacion;
    cout << "Digite el numero de pasaporte\n";
    cin >> numPasaporte;
    cout << "\n";
    for (i=0;i<=100;i++){
            if (datosViajeros[i].numPasaporte == numPasaporte){
            datosViajeros[i].verificacion = true;
            verificacion = datosViajeros[i].verificacion;
            ubicacion = i;
            }
    }
    if (verificacion == true){
            datosViajeros[ubicacion].numPasaporte =0;
            datosViajeros[ubicacion].nombreViajero ="";
            datosViajeros[ubicacion].nacionalidad = "";
            datosViajeros[ubicacion].lugarIngreso = "";
            datosViajeros[ubicacion].fechaSalida = "";
            datosViajeros[ubicacion].verificacion = false;
            cout << "Datos eliminados correctamente\n";

    } else {
        cout << "Numero de pasaporte no valido\n";

    }
}

 void consultarInfo() {
     int numPasaporte,ubicacion,i;
      bool verificacion;
    cout << "Digite el numero de pasaporte\n";
    cin >> numPasaporte;
    for (i=0;i<=100;i++){
            if (datosViajeros[i].numPasaporte == numPasaporte){
            datosViajeros[i].verificacion = true;
            verificacion = datosViajeros[i].verificacion;
            ubicacion = i;
            }
    }
    if (verificacion == true){
            cout << "Datos del viajero";
            cout << "Numero pasaporte: " << datosViajeros[ubicacion].numPasaporte << "\n";
            cout << "Nombre del viajero: " <<  datosViajeros[ubicacion].nombreViajero << "\n";
            cout << "Nacionalidad: " << datosViajeros[ubicacion].nacionalidad << "\n";
            cout << "Lugar ingreso: " << datosViajeros[ubicacion].lugarIngreso << "\n";
            cout << "Fecha salida: " << datosViajeros[ubicacion].fechaSalida << "\n";
    } else {
        cout << "Numero de pasaporte no valido\n";

    }
    cout << "<Pulse cualquier tecla para salir>";
	getch();
 }

   void generarReportes() {
       int opcion,i;
       cout << "Digite una opcion \n0)Generar nombres de viajeros\n1)Generar entradas y salidas\n2)Generar Nacionalidades viajeros\n3)Salir\n";
       cin >> opcion;
       do {
        switch(opcion) {
  case 0:
      for (i=0;i<=100;i++){
        cout << datosViajeros[i].nombreViajero << "\n";
      }
    break;
  case 1:
       for (i=0;i<=100;i++){
        cout << "Lugar Ingreso: " << datosViajeros[i].lugarIngreso << "\n";
        cout << "Fecha Salida: " << datosViajeros[i].fechaSalida << "\n";
      }
    break;
    case 2:
        for (i=0;i<=100;i++){
        cout << datosViajeros[i].nacionalidad << "\n";
      }
    break;
}
   } while (opcion != 3);
   }


int main() {
    int opcionMenu;
    do {
    cout << "**************************Menu Principal**************************\n\n";
    cout << "Digite una opcion \n\n0)Registrar Viajero\n1)Registrar Ingreso o salidas\n2)Borrar Registros\n3)Consultar Informacion\n4)Generar Reportes\n5)Salir\n\n";
    cin >> opcionMenu;
    cout << "\n";
switch(opcionMenu) {
  case 0:
      registrarViajeros();
    break;
  case 1:
      ingresoSalida();
    break;
    case 2:
       borrarRegistro();
    break;
     case 3:
       consultarInfo();
    break;
    case 4:
        generarReportes();
    break;
}
    } while (opcionMenu != 5);
  return 0;
}
