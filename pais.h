#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

class Pais{
private:
    int Id;
    char Nombre[30];
    char Continente[30];
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

    /// GET para Continente
    const char* getContinente(){
        return Continente;
    }
    /// SET para Continente
    void setContinente(const char* cont){
        strcpy(Continente, cont);
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
    void cargarPais(int id);
    void mostrarPais();
};

void Pais::cargarPais(int id){
    setId(id);

    cout << "Ingrese nombre del pais: ";
    cargarCadena(Nombre, 30);

    cout << "Ingrese nombre del continente: ";
    cargarCadena(Continente, 30);

    Estado = true;
}

void Pais::mostrarPais(){
    cout << "Id: " << Id << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Continente: " << Continente << endl;
}

#endif // PAIS_H_INCLUDED
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

class Pais{
private:
    int Id;
    char Nombre[30];
    char Continente[30];
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

    /// GET para Continente
    const char* getContinente(){
        return Continente;
    }
    /// SET para Continente
    void setContinente(const char* cont){
        strcpy(Continente, cont);
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
    void cargarPais(int id);
    void mostrarPais();
};

void Pais::cargarPais(int id){
    setId(id);
    cout << "Ingrese nombre del pais: ";
    cargarCadena(Nombre, 30);

    cout << "Ingrese nombre del continente: ";
    cargarCadena(Continente, 30);

    Estado = true;
}

void Pais::mostrarPais(){
    cout << "Id: " << Id << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Continente: " << Continente << endl;
}

#endif // PAIS_H_INCLUDED
