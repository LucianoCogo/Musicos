#ifndef MENUINSTRUMENTOS_H_INCLUDED
#define MENUINSTRUMENTOS_H_INCLUDED

void menuInstrumentos(){
    ArchivoInstrumento obj(ARCHIVO_INSTRUMENTOS);
    int opc;
    while(true){
        system("cls");
        cout << "MENU INSTRUMENTOS:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Agregar instrumentos." << endl;
        cout << "2 - Listar instrumento por ID." << endl;
        cout << "3 - Listar todo." << endl;
        cout << "4 - Modificar nombre." << endl;
        cout << "5 - Eliminar registro." << endl;
        cout << "------------------------" << endl;
        cout << "0 - Volver al menu principal." << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: obj.agregarInstrumento();
                    break;
            case 2: obj.buscarPorIdInstrumento();
                    break;
            case 3: obj.mostrarListadoInstrumento();
                    break;
            case 4: obj.modificarNombreInstrumento();
                    break;
            case 5: obj.bajaLogicaInstrumento();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // MENUINSTRUMENTOS_H_INCLUDED
