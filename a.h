#ifndef A_H_INCLUDED
#define A_H_INCLUDED

/// Declaracion de funciones
int repeDNI(int d);
int checkIdInstrumento(int idIns);
int checkIdPais(int idP);
Fecha checkFechaActual(Fecha obj);

/// Desarrollo de funciones
int repeDNI(int d){
    Musico obj;
    FILE *pMusico;
    pMusico = fopen("musicos.dat", "rb");
    if(pMusico == NULL){
        //cout << "No se pudo leer el archivo." << endl;
        //system("pause");
        //return 2;
    }
    while(fread(&obj, sizeof obj, 1, pMusico) == 1){
        if (d == obj.getDNI()){
            fclose(pMusico);
            return 0; /// El DNI ya existe en la base de datos
        }
    }
    fclose(pMusico);
    return 1; /// El DNI no existe en la base de datos
}

int checkIdInstrumento(int idIns){
    Instrumento obj;
    FILE *pInstrumento;
    pInstrumento = fopen("instrumentos.dat", "rb");
    if(pInstrumento == NULL){
        cout << "No se pudo leer el archivo." << endl;
        system("pause");
        return -1;
    }
    while(fread(&obj, sizeof obj, 1, pInstrumento) == 1) {
        if (idIns == obj.getId() && obj.getEstado() == true) {
            fclose(pInstrumento);
            return 0;
        }
    }
    fclose(pInstrumento);
    return 1;
}

int checkIdPais(int idP){
    Pais obj;
    FILE *pPais;
    pPais = fopen("paises.dat", "rb");
    if(pPais == NULL){
        cout << "No se pudo leer el archivo." << endl;
        system("pause");
        return -1;
    }
    while(fread(&obj, sizeof obj, 1, pPais) == 1) {
        if (idP == obj.getId() && obj.getEstado() == true) {
            fclose(pPais);
            return 0;
        }
    }
    fclose(pPais);
    return 1;
}

Fecha checkFechaActual(Fecha obj) {
    Fecha objetoFechaActual;
    int checkDia, checkMes, checkAnio;

    objetoFechaActual.fechaActual(checkDia, checkMes, checkAnio);

    while (true) {
        Fecha ingreso;
        ingreso.cargarFecha();

        if (ingreso.getAnio() < checkAnio ||
            (ingreso.getAnio() == checkAnio && ingreso.getMes() < checkMes) ||
            (ingreso.getAnio() == checkAnio && ingreso.getMes() == checkMes && ingreso.getDia() <= checkDia)) {
            return obj;
        }

        cout << "La fecha debe ser igual o anterior a la fecha actual." << endl;
        cout << "Por favor, vuelva a ingresar la fecha de inscripcion: " << endl;
    }
}

#endif // A_H_INCLUDED
