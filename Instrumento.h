#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

class Instrumento{
private:
    int Id;
    char Nombre[30];
    int Clasificacion;
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

    /// GET para Clasificacion
    int getClasificacion(){
        return Clasificacion;
    }
    /// SET para Clasificacion
    void setClasificacion(int clasificacion){
        Clasificacion = clasificacion;
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
    void cargarInstrumento(int id);
    void mostrarInstrumento();
};

void Instrumento::cargarInstrumento(int id){
    setId(id);

    cout << "Ingrese nombre del instrumento: ";
    cargarCadena(Nombre, 30);

    cout << "Ingrese el numero de clasificacion: ";
    cin >> Clasificacion;

    Estado = true;
}

void Instrumento::mostrarInstrumento(){
    cout << "Id: " << Id << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Codigo de clasificacion: " << Clasificacion << endl;
}

#endif // INSTRUMENTO_H_INCLUDED
