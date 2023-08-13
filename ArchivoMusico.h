#ifndef ARCHIVOMUSICO_H_INCLUDED
#define ARCHIVOMUSICO_H_INCLUDED

/// Las variables de atributo de la clase, llevan mayusculas al inicio de cada "palabra".
/// Las variables locales estan escritas totalmente en minusculas.

class ArchivoMusico{
    private:
        char Nombre[30];
    public:
    ArchivoMusico(const char *nombre){
        strcpy(Nombre, nombre);
    }

    /// Funciones de la clase
    void agregarMusico();
    void buscarPorDNI();
    void mostrarListadoMusicos();
    void modificarFechaInscripcion();
    void bajaLogicaMusico();
    int posicionMusico(int d);
    Musico leerMusico(int p);
    bool sobreEscribirMusico(Musico obj, int pos);
};

void ArchivoMusico::agregarMusico() {
    Musico obj;
    obj.cargarMusico();
    FILE* pMusico = fopen(Nombre, "ab");
    if (pMusico == NULL) {
        cout << "No se pudo crear el archivo" << endl;
        return;
    }

    fwrite(&obj, sizeof(Musico), 1, pMusico);
    fclose(pMusico);
}

void ArchivoMusico::buscarPorDNI(){
    Musico obj;
    int DNI;
    cout << "Ingrese el DNI a buscar: ";
    cin >> DNI;
    int pos = posicionMusico(DNI);

        if (pos == -3){
            cout << "El DNI ingresado se encuentra dado de baja." << endl;
            system("pause");
            return;
        }

        if (pos == -2){
            cout << "El archivo no existe o no se pudo abrir." << endl;
            system("pause");
            return;
        }

        if (pos == -1){
            cout << "El DNI ingresado no se encuentra en la base de datos." << endl;
            system("pause");
            return;
        }

    obj = leerMusico(pos);
        if(obj.getDNI()>0){
        obj.mostrarMusico();
        system("pause");
        }
            else if(obj.getDNI()==-3 || obj.getDNI()==-1){
            system("pause");
            cout << "Error de archivo." << endl;
            }
                else{
                cout << "No se pudo abrir el archivo." << endl;
                system("pause");
                }
}

void ArchivoMusico::mostrarListadoMusicos(){
    Musico obj;
    FILE *pMusico;
    pMusico = fopen(Nombre, "rb");
    if(pMusico == NULL){
        cout << "No se pudo leer el archivo o no existe." << endl;
        system("pause");
        return;
    }

	while(fread(&obj, sizeof obj, 1, pMusico)==1){
        if(obj.getEstado() == true){
            obj.mostrarMusico();
            cout << endl;
        }
    }
	system("pause");
	fclose(pMusico);
}

void ArchivoMusico::modificarFechaInscripcion(){
    Musico obj;
    int DNI;
    cout << "Ingrese el DNI del musico al que se le quiere modificar la fecha de inscripcion: ";
    cin >> DNI;
    int pos = posicionMusico(DNI);

    if (pos == -3){
            cout << "El DNI ingresado se encuentra dado de baja." << endl;
            system("pause");
            return;
        }

        if (pos == -2){
            cout << "El archivo no existe o no se pudo abrir." << endl;
            system("pause");
            return;
        }

        if (pos == -1){
            cout << "El DNI ingresado no se encuentra en la base de datos." << endl;
            system("pause");
            return;
        }

    obj = leerMusico(pos);
    Fecha f;
    cout << "Ingrese una nueva fecha de inscripcion: " << endl;
    f.cargarFecha();
    obj.setFechaIngreso(f);
    if (sobreEscribirMusico(obj, pos) == true){
        cout << "La fecha de ingreso fue modificada." << endl;
    }
        else{
            cout << "Se produjo un error al intentar modificar la fecha. Por favor, intente nuevamente.";
        }
    system("Pause");
    return;
}

void ArchivoMusico::bajaLogicaMusico() {
    Musico obj;
    int dni;
    cout << "Ingrese el DNI del músico a dar de baja: ";
    cin >> dni;
    int pos = posicionMusico(dni);
    if (pos == -3) {
        cout << "El DNI ingresado ya se encuentra dado de baja." << endl;
        system("pause");
        return;
    }
    if (pos == -2) {
        cout << "El archivo no existe o no se pudo abrir." << endl;
        system("pause");
        return;
    }
    if (pos == -1) {
        cout << "El DNI ingresado no se encuentra en la base de datos." << endl;
        system("pause");
        return;
    }

    obj = leerMusico(pos);
    if (obj.getDNI() == -1){
        cout << "Hubo un fallo al buscar el DNI. Por favor, vuelva a intentarlo." << endl;
        system("pause");
        return;
    }
    if (obj.getDNI() == -2){
        cout << "El archivo no existe o no se pudo abrir." << endl;
        system("pause");
        return;
    }
    if (obj.getDNI() > 0){
        obj.setEstado(false);
        if (sobreEscribirMusico(obj, pos)) {
            cout << "El musico fue dado de baja." << endl;
        } else {
            cout << "Se produjo un error al intentar dar de baja al músico. Inténtelo nuevamente." << endl;
        }
    }
    system("pause");
    return;
}

int ArchivoMusico::posicionMusico(int d) {
    Musico obj;
    int pos = 0;
    FILE* pMusico;
    pMusico = fopen(Nombre, "rb");
    if (pMusico == NULL) {
        return -2;
    }
    while (fread(&obj, sizeof obj, 1, pMusico) == 1) {
        if (obj.getDNI() == d && obj.getEstado() == false) {
            return -3;
        }
        if (obj.getDNI() == d) {
            fclose(pMusico);
            return pos;
        }
        pos++;
    }
    fclose(pMusico);
    return -1;
}

Musico ArchivoMusico::leerMusico(int p) {
    Musico obj;
    if (p < 0) {
        obj.setDNI(-1);
        return obj;
    }
    FILE* pMusico;
    pMusico = fopen(Nombre, "rb");
    if (pMusico == NULL) {
        obj.setDNI(-2);
        return obj;
    }
    fseek(pMusico, sizeof obj * p, 0);
    fread(&obj, sizeof obj, 1, pMusico);
    fclose(pMusico);
    return obj;
}

bool ArchivoMusico::sobreEscribirMusico(Musico obj, int pos) {
    FILE* pMusico;
    pMusico = fopen(Nombre, "rb+");
    if (pMusico == NULL) {
        cout << "Error de escritura." << endl;
        system("pause");
        return false;
    }
    fseek(pMusico, sizeof obj * pos, 0);
    fwrite(&obj, sizeof obj, 1, pMusico);
    fclose(pMusico);
    return true;
}

#endif // ARCHIVOMUSICO_H_INCLUDED
