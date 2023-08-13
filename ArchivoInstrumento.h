#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class ArchivoInstrumento{
    private:
        char Nombre[30];
    public:
    ArchivoInstrumento(const char *nombre){
        strcpy(Nombre, nombre);
    }

    /// Funciones de la clase
    void agregarInstrumento();
    void buscarPorIdInstrumento();
    void mostrarListadoInstrumento();
    void modificarNombreInstrumento();
    void bajaLogicaInstrumento();
    int posicionInstrumento(int d);
    Instrumento leerInstrumento(int p);
    bool sobreEscribirInstrumento(const Instrumento obj, int p);
};

void ArchivoInstrumento::agregarInstrumento() {
    Instrumento obj;
    int id;
    FILE *pInstrumento;
    pInstrumento = fopen(Nombre, "rb");
    if (pInstrumento == NULL) {
        id = 1;
    } else{
        fseek(pInstrumento, -sizeof obj, 2);
        if (fread(&obj, sizeof obj, 1, pInstrumento) == 1){
            id = obj.getId() + 1;
        }
    }

    fclose(pInstrumento);

    pInstrumento = fopen(Nombre, "ab");
    if (pInstrumento == NULL) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    obj.cargarInstrumento(id);
    fwrite(&obj, sizeof(Instrumento), 1, pInstrumento);
    fclose(pInstrumento);
}

void ArchivoInstrumento::buscarPorIdInstrumento(){
    Instrumento obj;
    int Id;
    cout << "Ingrese el Id a buscar: ";
    cin >> Id;

    int pos = posicionInstrumento(Id);
        if (pos == -3){
            cout << "El instrumento esta dado de baja." << endl;
            system("pause");
            return;
        }

        if (pos == -2){
            cout << "El archivo no existe o no se pudo abrir." << endl;
            system("pause");
            return;
        }

        if (pos == -1){
            cout << "El Id ingresado no se encuentra en la base de datos." << endl;
            system("pause");
            return;
        }

    obj = leerInstrumento(pos);
        if(obj.getId()>0){
        obj.mostrarInstrumento();
        system("pause");
        }
            else if(obj.getId()==-3 || obj.getId()==-1){
            cout << "Error de archivo." << endl;
            system("pause");
            }
                else{
                cout << "No se pudo abrir el archivo." << endl;
                system("pause");
                }
}

void ArchivoInstrumento::mostrarListadoInstrumento(){
    Instrumento obj;
    FILE *pInstrumento;
    pInstrumento = fopen(Nombre, "rb");
    if(pInstrumento == NULL){
        cout << "No se pudo leer el archivo o no existe." << endl;
        system("pause");
        return;
    }

	while(fread(&obj, sizeof obj, 1, pInstrumento)==1){
        if(obj.getEstado() == true){
            obj.mostrarInstrumento();
            cout << endl;
        };
    }
	system("pause");
	fclose(pInstrumento);
}

void ArchivoInstrumento::modificarNombreInstrumento(){
    Instrumento obj;
    int Id;
    cout << "Ingrese el Id del instrumento que quiere modificar: ";
    cin >> Id;

    int pos = posicionInstrumento(Id);
        if (pos == -3){
            cout << "El instrumento esta dado de baja." << endl;
            system("pause");
            return;
        }

        if (pos == -2){
            cout << "El archivo no existe o no se pudo abrir." << endl;
            system("pause");
            return;
        }

        if (pos == -1){
            cout << "El Id ingresado no se encuentra en la base de datos." << endl;
            system("pause");
            return;
        }

    obj = leerInstrumento(pos);
    char nombreMod[30];
    cout << "Ingrese el nombre: ";
    cin >> nombreMod;
    obj.setNombre(nombreMod);
    if (sobreEscribirInstrumento(obj, pos) == true){
        cout << "El nombre del instrumento fue modificado." << endl;
    }
        else{
            cout << "Se produjo un error al intentar modificar el nombre del instrumento. Por favor, intente nuevamente.";
        }
    system("Pause");
    return;
}

void ArchivoInstrumento::bajaLogicaInstrumento(){
    Instrumento obj;
    int Id;
    cout << "Ingrese el Id del instrumento a borrar: ";
    cin >> Id;
    int pos = posicionInstrumento(Id);
    if (pos == -3){
        cout << "El instrumento ya fue dado de baja." << endl;
        system("pause");
        return;
    }

    if (pos == -2){
        cout << "El archivo no existe o no se pudo abrir." << endl;
        system("pause");
        return;
    }

    if (pos == -1){
        cout << "El Id ingresado no se encuentra en la base de datos." << endl;
        system("pause");
        return;
    }

    obj = leerInstrumento(pos);
    if (obj.getId() == -1){
        cout << "Hubo un fallo al buscar el Id. Por favor, vuelva a intentarlo." << endl;
        system("pause");
        return;
    }
    if (obj.getId() == -2){
        cout << "El archivo no existe o no se pudo abrir." << endl;
        system("pause");
        return;
    }
    if (obj.getId() > 0){
        obj.setEstado(false);
        if(sobreEscribirInstrumento(obj, pos)) {
            cout << "El instrumento fue dado de baja." << endl;
        } else {
            cout << "Se produjo un error al intentar dar de baja el instrumento. Inténtelo nuevamente." << endl;
        }
    }
    system("pause");
    return;
}

int ArchivoInstrumento::posicionInstrumento(int d){
    Instrumento obj;
    int pos = 0;
    FILE *pInstrumento;
    pInstrumento = fopen(Nombre, "rb");
    if(pInstrumento == NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, pInstrumento) == 1){
        if(obj.getId() == d && obj.getEstado() == false){
            fclose(pInstrumento);
            return -3;
        }

        if(obj.getId() == d){
            fclose(pInstrumento);
            return pos;
        }
        pos++;
	}
	fclose(pInstrumento);
	return -1;
}

Instrumento ArchivoInstrumento::leerInstrumento(int p){
    Instrumento obj;
    if( p < 0){
        obj.setId(-1);
        return obj;
    }
    FILE *pInstrumento;
    pInstrumento = fopen(Nombre, "rb");
    if(pInstrumento == NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pInstrumento, sizeof obj * p, 0);
    fread(&obj, sizeof obj, 1, pInstrumento);
    fclose(pInstrumento);
    return obj;
}

bool ArchivoInstrumento::sobreEscribirInstrumento(const Instrumento obj, int p){
    FILE *pInstrumento;
    pInstrumento = fopen(Nombre, "rb+");
    if(pInstrumento == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        return false;
    }
    fseek(pInstrumento, p*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, pInstrumento);
	fclose(pInstrumento);
	return true;
}

#endif // ARCHIVOINSTRUMENTO_H_INCLUDED
