#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class ArchivoGenero{
    private:
        char Nombre[30];
    public:
    ArchivoGenero(const char *nombre){
        strcpy(Nombre, nombre);
    }

    /// Funciones de la clase
    void agregarGenero();
    void buscarPorIdGenero();
    void mostrarListadoGeneros();
    void modificarAnioGenero();
    void bajaLogicaGenero();
    int posicionGenero(int d);
    Genero leerGenero(int p);
    bool sobreEscribirGenero(const Genero obj, int pos);
};

void ArchivoGenero::agregarGenero() {
    Genero obj;
    int id;
    FILE *pGenero;
    pGenero = fopen(Nombre, "rb");
    if (pGenero == NULL) {
        id = 1;
    } else{
        fseek(pGenero, -sizeof obj, 2);
            if (fread(&obj, sizeof obj, 1, pGenero) == 1){
                id = obj.getId() + 1;
            }
    }

    fclose(pGenero);

    pGenero = fopen(Nombre, "ab");
    if (pGenero == NULL) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    if (obj.cargarGenero(id)){
        fwrite(&obj, sizeof(Genero), 1, pGenero);
        fclose(pGenero);
    }
    fclose(pGenero);
}

void ArchivoGenero::buscarPorIdGenero(){
    Genero obj;
    int Id;
    cout << "Ingrese el Id a buscar: ";
    cin >> Id;

    int pos = posicionGenero(Id);
        if (pos == -3){
            cout << "El genero esta dado de baja." << endl;
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

    obj = leerGenero(pos);
        if(obj.getId()>0){
        obj.mostrarGenero();
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

void ArchivoGenero::mostrarListadoGeneros(){
    Genero obj;
    FILE *pGenero;
    pGenero = fopen(Nombre, "rb");
    if(pGenero == NULL){
        cout << "No se pudo leer el archivo o no existe." << endl;
        system("pause");
        return;
    }

	while(fread(&obj, sizeof obj, 1, pGenero)==1){
        if(obj.getEstado() == true){
            obj.mostrarGenero();
            cout << endl;
        };
    }
	system("pause");
	fclose(pGenero);
}

void ArchivoGenero::modificarAnioGenero(){
    Genero obj;
    int Id;
    cout << "Ingrese el Id del genero que quiere modificar: ";
    cin >> Id;
    int pos = posicionGenero(Id);

        if (pos == -3){
            cout << "El genero esta dado de baja." << endl;
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

    obj = leerGenero(pos);
    int aniodeorigen;
    cout << "Ingrese el anio de origen: ";
    cin >> aniodeorigen;
    obj.setAnioDeOrigen(aniodeorigen);
    if (sobreEscribirGenero(obj, pos) == true){
        cout << "El anio de origen fue modificado." << endl;
    }
        else{
            cout << "Se produjo un error al intentar modificar el anio de origen. Por favor, intente nuevamente.";
        }
    system("Pause");
    return;
}

void ArchivoGenero::bajaLogicaGenero(){
    Genero obj;
    int Id;
    cout << "Ingrese el Id del genero a borrar: ";
    cin >> Id;
    int pos = posicionGenero(Id);
    if (pos == -3){
            cout << "El genero ya fue dado de baja." << endl;
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

    obj = leerGenero(pos);
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
        if(sobreEscribirGenero(obj, pos)) {
            cout << "El genero fue dado de baja." << endl;
        } else {
            cout << "Se produjo un error al intentar dar de baja el genero. Inténtelo nuevamente." << endl;
        }
    }
    system("pause");
    return;
}

int ArchivoGenero::posicionGenero(int d){
    Genero obj;
    int pos = 0;
    FILE *pGenero;
    pGenero = fopen(Nombre, "rb");
    if(pGenero == NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, pGenero) == 1){
        if(obj.getId() == d && obj.getEstado() == false){
            fclose(pGenero);
            return -3;
        }

        if(obj.getId() == d){
            fclose(pGenero);
            return pos;
        }
        pos++;
	}
	fclose(pGenero);
	return -1;
}

Genero ArchivoGenero::leerGenero(int p){
    Genero obj;
    if (p < 0){
        obj.setId(-1);
        return obj;
    }
    FILE *pGenero;
    pGenero = fopen(Nombre, "rb");
    if(pGenero == NULL){
        obj.setId(-2);
        return obj;
    }
    fseek(pGenero, sizeof obj * p, 0);
    fread(&obj, sizeof obj, 1, pGenero);
    fclose(pGenero);
    return obj;
}

bool ArchivoGenero::sobreEscribirGenero(const Genero obj, int pos){
    FILE *pGenero;
    pGenero = fopen(Nombre, "rb+");
    if(pGenero == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        system("pause");
        return false;
    }
    fseek(pGenero, sizeof obj * pos, 0);
    fwrite(&obj, sizeof obj, 1, pGenero);
	fclose(pGenero);
	return true;
}

#endif // ARCHIVOGENERO_H_INCLUDED
