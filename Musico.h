#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

int checkIdInstrumento(int idIns);
int repeDNI(int d);
Fecha checkFechaActual(Fecha obj);

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class Musico{
private:
    int DNI;
    char Nombre[30];
    char Apellido[30];
    char EMail[30];
    char Telefono[30];
    int Claustro;
    int InstrumentoPrincipal;
    int TipoDeMusica;
    float Matricula;
    bool Estado;
    Fecha Ingreso;

public:
    /// GET para DNI
    int getDNI(){
        return DNI;
    }
    /// SET para el DNI
    void setDNI(int dni){
            DNI = dni;
    }

    /// GET para nombre
    const char* getNombre(){
        return Nombre;
    }
    /// SET para nombre
    void setNombre(const char* nombre){
        strcpy(Nombre, nombre);
    }

    /// GET para apellido
    const char* getApellido(){
        return Apellido;
    }
    /// SET para apellido
    void setApellido(const char* apellido){
        strcpy(Apellido, apellido);
    }

    /// GET para email
    const char* getEMail(){
        return EMail;
    }
    /// SET para email
    void setEMail(const char* email){
        strcpy(EMail, email);
    }

    /// GET para telefono
    const char* getTelefono(){
        return Telefono;
    }
    /// SET para telefono
    void setTelefono(const char* telefono){
        strcpy(Telefono, telefono);
    }

    /// GET para Claustro
    int getClaustro(){
    return Claustro;
    }
    /// SET para Claustro
    void setClaustro(int claustro){
        if (claustro >= 1 && claustro <= 4){
            Claustro = claustro;
        }
            else {
                cout << "-------------------------------------" << endl;
                cout << "ERROR - El numero ingresado es incorrecto. Ingrese un numero entre 1 y 4: " << endl;
                cout << "-------------------------------------" << endl;
                cout << "Ingrese el Claustro (1: docente; 2 alumno; 3 no docente; 4 graduado): ";
                int nuevoClaustro;
                cin >> nuevoClaustro;
                setClaustro(nuevoClaustro);
        }
    }

    /// GET para instrumento principal
    int getInstrumentoPrincipal() {
        return InstrumentoPrincipal;
    }
    /// SET para instrumento principal
    bool setInstrumentoPrincipal(int instrumentoprincipal) {
    bool instrumentoValido = true;
    switch (checkIdInstrumento(instrumentoprincipal)) {
        case -1:
            instrumentoValido = false;
            break;
        case 0:
            InstrumentoPrincipal = instrumentoprincipal;
            break;
        case 1:
            cout << "-------------------------------------" << endl;
            cout << "ERROR - El instrumento no existe en la base de datos. Puede ingresar 0 como instrumento principal para salir." << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese el Instrumento Principal: ";
            cin >> instrumentoprincipal;
            if (instrumentoprincipal == 0){
                instrumentoValido = false;
                break;
            }

            instrumentoValido = setInstrumentoPrincipal(instrumentoprincipal);
            break;
    }
    return instrumentoValido;
}

    /// GET para TipoDeMusica
    int getTipoDeMusica() {
    return TipoDeMusica;
    }
    /// SET para TipoDeMusica
    void setTipoDeMusica(int tipodemusica) {
        if (tipodemusica >= 1 && tipodemusica <= 10){
            TipoDeMusica = tipodemusica;
        }
            else{
                cout << "-------------------------------------" << endl;
                cout << "ERROR - El numero ingresado es incorrecto. Ingrese un numero entre 1 y 10: " << endl;
                cout << "-------------------------------------" << endl;
                cout << "Ingrese el Tipo de Musica (1-10): ";
                int nuevoTipo;
                cin >> nuevoTipo;
                setTipoDeMusica(nuevoTipo);
        }
    }

    /// GET para Matricula
    float getMatricula() {
        return Matricula;
    }
    /// SET para Matricula
    void setMatricula(float matricula) {
        if (matricula >=0){
            Matricula = matricula;
        }
        else{
            cout << "-------------------------------------" << endl;
            cout << "ERROR - El monto abonado debe ser 0, en caso de no haber abonado, o el monto correspondiente: $" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese el monto pagado de la matricula: $";
            float nuevaMatricula;
            cin >> nuevaMatricula;
            setMatricula(nuevaMatricula);
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

    /// GET para la fecha de ingreso
    Fecha getFechaIngreso(){
        return Ingreso;
    }
    /// SET para la fecha de ingreso
    void setFechaIngreso(Fecha f) {
    Fecha objetoFechaActual;
    int checkDia, checkMes, checkAnio;
    objetoFechaActual.fechaActual(checkDia, checkMes, checkAnio);

    while (true) {
        if (f.getAnio() > checkAnio ||
            (f.getAnio() == checkAnio && f.getMes() > checkMes) ||
            (f.getAnio() == checkAnio && f.getMes() == checkMes && f.getDia() > checkDia)) {
            cout << "La fecha debe ser igual o anterior a la fecha actual." << endl;
            cout << "Por favor, vuelva a ingresar la fecha de inscripcion: " << endl;
            f.cargarFecha();
        } else {
            break;
        }
    }
    Ingreso = f;
}


    /// Funciones de la clase
    void cargarMusico();
    void mostrarMusico();
    int buscarDNI(int dni);
};

void Musico::cargarMusico() {
    int dni;
    cout << "Ingrese el DNI: ";
    cin >> dni;
    while (repeDNI(dni) == 0) {
        cout << "-------------------------------------" << endl;
        cout << "ERROR - El DNI ingresado ya se encuentra cargado en la base de datos. (Si no lo encuentra en lista, es posible que este dado de baja)" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese el DNI: ";
        cin >> dni;
    }
    setDNI(dni);

    cout << "Ingrese el Nombre: ";
    cargarCadena(Nombre, 30);

    cout << "Ingrese el Apellido: ";
    cargarCadena(Apellido, 30);

    cout << "Ingrese el EMail: ";
    cargarCadena(EMail, 30);

    cout << "Ingrese el Telefono: ";
    cin >> Telefono;

    int claustro;
    cout << "Ingrese el Claustro (1: docente; 2 alumno; 3 no docente; 4 graduado): ";
    cin >> claustro;
    setClaustro(claustro);

    int instrumentoprincipal;
    cout << "Ingrese el Instrumento Principal: ";
    cin >> instrumentoprincipal;
    if (setInstrumentoPrincipal(instrumentoprincipal) == false) {
        return;
    }

    int tipodemusica;
    cout << "Ingrese el Tipo de Musica (1-10): ";
    cin >> tipodemusica;
    setTipoDeMusica(tipodemusica);

    Fecha ingreso;
    cout << "Fecha de inscripcion: " << endl;
    ingreso.cargarFecha();
    setFechaIngreso(ingreso);

    float matricula;
    cout << "Ingrese el monto pagado de la matricula: $";
    cin >> matricula;
    setMatricula(matricula);

    Estado = true;
}

void Musico::mostrarMusico(){

    cout << "DNI: " << DNI << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "EMail: " << EMail << endl;
    cout << "Telefono: " << Telefono << endl;
    cout << "Claustro: " << Claustro << endl;
    cout << "Instrumento principal: " << InstrumentoPrincipal << endl;
    cout << "Tipo de Musica: " << TipoDeMusica << endl;
    cout << "Fecha de inscripcion es: ";
    Ingreso.mostrarFecha();
    cout << "Matricula abonada: $" << Matricula << endl;
}

#endif // MUSICO_H_INCLUDED
