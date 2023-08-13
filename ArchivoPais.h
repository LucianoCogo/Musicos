#ifndef ARCHIVOPAIS_H_INCLUDED
#define ARCHIVOPAIS_H_INCLUDED

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class ArchivoPais{
    private:
        char Nombre[30];
    public:
    ArchivoPais(const char *nombre){
        strcpy(Nombre, nombre);
    }

    /// Funciones de la clase
    void agregarPais();
    void buscarPorIdPais();
    void mostrarListadoPais();
    void modificarNombrePais();
    void bajaLogicaPais();
    int posicionPais(int d);
    Pais leerPais(int p);
    bool sobreEscribirPais(const Pais obj, int p);
};

void ArchivoPais::agregarPais() {
    Pais obj;
    int id;
    FILE *pPais;
    pPais = fopen(Nombre, "rb");
    if (pPais == NULL) {
        id = 1;
    } else{
        fseek(pPais, -sizeof obj, 2);
        if (fread(&obj, sizeof obj, 1, pPais) == 1){
            id = obj.getId() + 1;
        }
    }
    fclose(pPais);

    pPais = fopen(Nombre, "ab");
    if (pPais == NULL) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }
    obj.cargarPais(id);

    fwrite(&obj, sizeof(Pais), 1, pPais);
    fclose(pPais);
}

void ArchivoPais::buscarPorIdPais(){
    Pais obj;
    int Id;
    cout << "Ingrese el Id a buscar: ";
    cin >> Id;

    int pos = posicionPais(Id);
        if (pos == -3){
            cout << "El pais esta dado de baja." << endl;
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

    obj = leerPais(pos);
        if(obj.getId()>0){
        obj.mostrarPais();
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

void ArchivoPais::mostrarListadoPais(){
    Pais obj;
    FILE *pPais;
    pPais = fopen(Nombre, "rb");
    if(pPais == NULL){
        cout << "No se pudo leer el archivo o no existe." << endl;
        system("pause");
        return;
    }

	while(fread(&obj, sizeof obj, 1, pPais)==1){
        if(obj.getEstado() == true){
            obj.mostrarPais();
            cout << endl;
        };
    }
	system("pause");
	fclose(pPais);
}

void ArchivoPais::modificarNombrePais(){
    Pais obj;
    int Id;
    cout << "Ingrese el Id del pais que quiere modificar: ";
    cin >> Id;

    int pos = posicionPais(Id);
        if (pos == -3){
            cout << "El pais esta dado de baja." << endl;
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

    obj = leerPais(pos);
    char nombreMod[30];
    cout << "Ingrese el nombre: ";
    cin >> nombreMod;
    obj.setNombre(nombreMod);
    if (sobreEscribirPais(obj, pos) == true){
        cout << "El nombre del pais fue modificado." << endl;
    }
        else{
            cout << "Se produjo un error al intentar modificar el nombre del pais. Por favor, intente nuevamente.";
        }
    system("Pause");
    return;
}

void ArchivoPais::bajaLogicaPais(){
    Pais obj;
    int Id;
    cout << "Ingrese el Id del pais a borrar: ";
    cin >> Id;
    int pos = posicionPais(Id);
    if (pos == -3){
        cout << "El pais ya fue dado de baja." << endl;
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

    obj = leerPais(pos);
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
        if(sobreEscribirPais(obj, pos)) {
            cout << "El pais fue dado de baja." << endl;
        } else {
            cout << "Se produjo un error al intentar dar de baja el pais. Inténtelo nuevamente." << endl;
        }
    }
    system("pause");
    return;
}

int ArchivoPais::posicionPais(int d){
    Pais obj;
    int pos = 0;
    FILE *pPais;
    pPais = fopen(Nombre, "rb");
    if(pPais == NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, pPais) == 1){
        if(obj.getId() == d && obj.getEstado() == false){
            fclose(pPais);
            return -3;
        }

        if(obj.getId() == d){
            fclose(pPais);
            return pos;
        }
        pos++;
	}
	fclose(pPais);
	return -1;
}

Pais ArchivoPais::leerPais(int p){
    Pais obj;
    if (p < 0){
        obj.setId(-1);
        return obj;
    }
    FILE *pPais;
    pPais = fopen(Nombre, "rb");
    if(pPais == NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pPais, sizeof obj * p, 0);
    fread(&obj, sizeof obj, 1, pPais);
    fclose(pPais);
    return obj;
}

bool ArchivoPais::sobreEscribirPais(const Pais obj, int p){
    FILE *pPais;
    pPais = fopen(Nombre, "rb+");
    if(pPais == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        return false;
    }
    fseek(pPais, p*sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, pPais);
	fclose(pPais);
	return true;
}

#endif // ARCHIVOPAIS_H_INCLUDED
