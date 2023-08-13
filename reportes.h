#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void inicializarVector(int vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        vec[i] = false;
    }
}

void NoInstrumento(){
    char nInstrumento[30];
    int idBuscar = -3;
    cout << "Ingrese el nombre del instrumento: ";
    cargarCadena(nInstrumento, 30);

    FILE *pInstrumento;
    pInstrumento = fopen("instrumentos.dat", "rb");
    if(pInstrumento == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        system("pause");
        return;
    }
    Instrumento obj1;
    while(fread(&obj1, sizeof (obj1), 1, pInstrumento) == 1){
        if (strcmp(nInstrumento, obj1.getNombre()) == 0) {
            idBuscar = obj1.getId();
            break;
        }
    }
    fclose(pInstrumento);
    if (idBuscar == -3){
        cout << "No se encontro un instrumento con el nombre ingresado" << endl;
        system("pause");
        return;
    }

    Musico obj2;
    FILE *pMusico;
    pMusico = fopen("musicos.dat", "rb");
    if(pMusico == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        system("pause");
        return;
    }

    FILE *pEstudiantes;
    pEstudiantes = fopen("estudiantes.dat", "wb");
    if(pEstudiantes == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        system("pause");
        return;
    }
    while (fread(&obj2, sizeof(obj2), 1, pMusico) == 1) {
        if (obj2.getInstrumentoPrincipal() != idBuscar && obj2.getClaustro() == 2 && obj2.getEstado()) {
            fwrite(&obj2, sizeof(obj2), 1, pEstudiantes);
        }
    }

    cout << "El archivo se genero correctamente" << endl;
    fclose(pMusico);
    fclose(pEstudiantes);
    system("pause");
    return;
}

void mostrarEstudiantes(){
    Musico obj;
    FILE *pEstudiantes;
    pEstudiantes = fopen("estudiantes.dat", "rb");
    if(pEstudiantes == NULL){
        cout << "No se pudo leer el archivo o no existe." << endl;
        system("pause");
        return;
    }

	while(fread(&obj, sizeof obj, 1, pEstudiantes)==1){
        obj.mostrarMusico();
        cout << endl;
    }
	system("pause");
	fclose(pEstudiantes);
}

void aniosSXXI(){
    int contVec[100];
    inicializarVector(contVec, 100);
    Genero obj;

    FILE *pGenero;
    pGenero = fopen("generos.dat", "rb");
    if(pGenero == NULL){
        cout<<"No se pudo abrir el archivo."<<endl;
        system("pause");
        return;
    }

    while(fread(&obj, sizeof obj, 1, pGenero)==1){
        if(obj.getAnioDeOrigen() >= 2000){
            contVec[obj.getAnioDeOrigen() - 2000]++;
        }
    }

    cout << "Los anios de origen con 3 o mas generos musicales son: " << endl;
    for (int i = 0; i<100; i++){
        if(contVec[i] == 3){
            cout << i + 2000;
        }
    }

    fclose(pGenero);
    system("pause");
    return;
}

void estudiantesDinamica(){
    Musico* vec;
    int cantElem = 0;

    Musico obj;
    FILE* pMusico;
    pMusico = fopen("musicos.dat", "rb");
    if (pMusico == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        system("pause");
        return;
    }

    while (fread(&obj, sizeof obj, 1, pMusico) == 1){
        if (obj.getClaustro() == 2){
            cantElem++;
        }
    }
    fclose(pMusico);

    vec = new Musico[cantElem];
    if (vec == NULL) {
        cout << "No se pudo asignar la memoria" << endl;
        system("pause");
        return;
    }

    pMusico = fopen("musicos.dat", "rb");
    if (pMusico == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        system("pause");
        delete[] vec;
        return;
    }

    int pos = 0;
    while (fread(&obj, sizeof obj, 1, pMusico) == 1){
        if (obj.getClaustro() == 2){
            vec[pos] = obj;
            pos++;
        }
    }
    fclose(pMusico);

    for (int i = 0; i < cantElem; i++){
        vec[i].mostrarMusico();
        cout << endl;
    }

    delete[] vec;
    system("pause");
    return;
}


void menuReportes(){
    int opc;

    while(true){
        system("cls");
        cout << "REPORTES:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Punto 1 - Generar archivo" << endl;
        cout << "2 - Punto 1 - Mostrar archivo" << endl;
        cout << "3 - Punto 2 - Mostrar anios origen del Siglo XXI con una cantidad de generos musicales iguales a 3" << endl;
        cout << "4 - Punto 3 - Listado de estudiantes utilizando un vector con asignacion dinamica" << endl;
        cout << "------------------------" << endl;
        cout << "0 - Volver al menu principal." << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: NoInstrumento();
                    break;
            case 2: mostrarEstudiantes();
                    break;
            case 3: aniosSXXI();
                    break;
            case 4: estudiantesDinamica();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // REPORTES_H_INCLUDED
