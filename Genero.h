#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

int checkIdPais(int idP);

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class Genero{
private:
    int Id;
    char Nombre[30];
    int PaisDeOrigen;
    int AnioDeOrigen;
    bool Estado;

public:
    /// GET para Id
    int getId(){
        return Id;
    }
    /// SET para el Id
    void setId(int id){
            Id = id;
    }

    /// GET para nombre
    const char* getNombre(){
        return Nombre;
    }
    /// SET para nombre
    void setNombre(const char* nombre){
        strcpy(Nombre, nombre);
    }

    /// GET para pais de origen
    int getPaisDeOrigen(){
        return PaisDeOrigen;
    }
    /// SET para pais de origen
    bool setPaisDeOrigen(int paisdeorigen){
        bool paisValido = true;
        switch (checkIdPais(paisdeorigen)) {
            case -1: paisValido = false;
            break;
            case 0: PaisDeOrigen = paisdeorigen;
            break;
            case 1:
            cout << "-------------------------------------" << endl;
            cout << "ERROR - El pais no existe en la base de datos. Puede ingresar 0 como pais para salir." << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese el pais de origen: ";
            cin >> paisdeorigen;
            if (paisdeorigen == 0){
                paisValido = false;
                break;
            }

            paisValido = setPaisDeOrigen(paisdeorigen);
            break;
    }
    return paisValido;
}

    /// GET para año de origen
    int getAnioDeOrigen(){
        return AnioDeOrigen;
    }
    /// SET para pais de origen
    void setAnioDeOrigen(int aniodeorigen){
        if (aniodeorigen >= 1500 && aniodeorigen <= 2023){
            AnioDeOrigen = aniodeorigen;
        }
            else{
                cout << "-------------------------------------" << endl;
                cout << "ERROR - Los anios de origen validos van entre el anio 1500 d.C y el anio actual: " << endl;
                cout << "-------------------------------------" << endl;
                cout << "Ingrese el anio de origen: ";
                int nuevoanio;
                cin >> nuevoanio;
                setAnioDeOrigen(nuevoanio);
            }
    }

        /// GET para Estado
    bool getEstado() {
        return Estado;
    }
    /// SET para Estado
    void setEstado(bool estado) {
        Estado = estado;
    }

    /// Funciones de la clase
    bool cargarGenero(int id);
    void mostrarGenero();
};

bool Genero::cargarGenero(int id){
    setId(id);

    cout << "Ingrese nombre del genero: ";
    cargarCadena(Nombre, 30);

    int paisdeorigen;
    cout << "Ingrese el codigo de pais de origen: ";
    cin >> paisdeorigen;
    if (setPaisDeOrigen(paisdeorigen) == false){
        return false;
    }

    int aniodeorigen;
    cout << "Ingrese el anio de origen: ";
    cin >> aniodeorigen;
    setAnioDeOrigen(aniodeorigen);

    Estado = true;
    return true;
}

void Genero::mostrarGenero(){
    cout << "Id: " << Id << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Codigo de pais de origen: " << PaisDeOrigen << endl;
    cout << "Anio de origen: " << AnioDeOrigen << endl;
}

#endif // GENERO_H_INCLUDED
