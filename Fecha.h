#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class Fecha{
private:
    int Dia;
    int Mes;
    int Anio;

public:
    /// GET para el dia
    int getDia(){
        return Dia;
    }
    /// SET para el dia
    void setDia(int dia) {
        if (dia >= 1 && dia <= 31) {
            Dia = dia;
    }
    else {
        cout << "-------------------------------------" << endl;
        cout << "ERROR - El numero de dia ingresado es incorrecto. Por favor, ingrese un numero de dia entre 1 y 31" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Ingrese el Dia: ";
        int nuevoDia;
        cin >> nuevoDia;
        setDia(nuevoDia);
        }
    }

    /// GET para el mes
    int getMes(){
        return Mes;
    }
    /// SET para el mes
    void setMes(int mes) {
        if (mes >= 1 && mes <= 12) {
            Mes = mes;
        }
        else {
            cout << "-------------------------------------" << endl;
            cout << "ERROR - El numero de mes ingresado es incorrecto. Por favor, ingrese un numero de mes entre 1 y 12" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Ingrese el Mes: ";
            int nuevoMes;
            cin >> nuevoMes;
            setMes(nuevoMes);
        }
    }

    /// GET para el año
    int getAnio(){
        return Anio;
    }

    /// SET para el año
    void setAnio(int anio){
        Anio = anio;
    }

    ///Funciones de la clase
    void cargarFecha();
    void mostrarFecha();
    void modificarFecha(int nuevoDia, int nuevoMes, int nuevoAnio);
    void fechaActual(int& dia, int& mes, int& anio);
};

void Fecha::cargarFecha(){
    int dia;
    cout << "Ingrese el Dia: ";
    cin >> dia;
    setDia(dia);

    int mes;
    cout << "Ingrese el Mes: ";
    cin >> mes;
    setMes(mes);

    cout << "Ingrese el Anio: ";
    cin >> Anio;
}

void Fecha::mostrarFecha(){
    cout << Dia << "/" << Mes << "/" << Anio << "." << endl;
}

void Fecha::modificarFecha(int nuevoDia, int nuevoMes, int nuevoAnio) {
    setDia(nuevoDia);
    setMes(nuevoMes);
    setAnio(nuevoAnio);
}

void Fecha::fechaActual(int& dia, int& mes, int& anio) {
    time_t tiempoActual = time(nullptr);
    tm* fechaActual = localtime(&tiempoActual);

    dia = fechaActual->tm_mday;
    mes = fechaActual->tm_mon + 1;
    anio = fechaActual->tm_year + 1900;
}

#endif // FECHA_H_INCLUDED
