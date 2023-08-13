#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

const char *ARCHIVO_MUSICOS = "musicos.dat";
const char *ARCHIVO_GENEROS = "generos.dat";
const char *ARCHIVO_INSTRUMENTOS = "instrumentos.dat";
const char *ARCHIVO_PAISES = "paises.dat";

void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

#include "Fecha.h"
#include "Musico.h"
#include "Genero.h"
#include "Instrumento.h"
#include "Pais.h"
#include "Configuracion.h"
#include "a.h"
#include "ArchivoMusico.h"
#include "ArchivoGenero.h"
#include "ArchivoInstrumento.h"
#include "ArchivoPais.h"
#include "MenuMusicos.h"
#include "MenuGeneros.h"
#include "MenuInstrumentos.h"
#include "MenuPais.h"
#include "MenuConfiguracion.h"
#include "reportes.h"

int main(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU PRINCIPAL:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Menu Musicos." << endl;
        cout << "2 - Menu Generos." << endl;
        cout << "3 - Menu Instrumentos." << endl;
        cout << "4 - Menu Pais." << endl;
        cout << "5 - Reportes." << endl;
        cout << "6 - Configuracion." << endl;
        cout << "------------------------" << endl;
        cout << "0 - Fin del programa." << endl;
        cout << endl;
        cout << "Seleccione una de las opciones: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: menuMusicos();
                    break;
            case 2: menuGeneros();
                    break;
            case 3: menuInstrumentos();
                    break;
            case 4: menuPaises();
                    break;
            case 5: menuReportes();
                    break;
            case 6: menuConfiguracion();
                    break;
            case 0:
                return 0;
                break;
            }
        system("cls");
    }
    return 0;
}
