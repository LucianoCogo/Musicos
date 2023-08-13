#ifndef MENUPAIS_H_INCLUDED
#define MENUPAIS_H_INCLUDED

void menuPaises(){
    ArchivoPais obj(ARCHIVO_PAISES);
    int opc;
    while(true){
        system("cls");
        cout << "MENU PAISES:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Agregar pais." << endl;
        cout << "2 - Listar pais por ID." << endl;
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
            case 1: obj.agregarPais();
                    break;
            case 2: obj.buscarPorIdPais();
                    break;
            case 3: obj.mostrarListadoPais();
                    break;
            case 4: obj.modificarNombrePais();
                    break;
            case 5: obj.bajaLogicaPais();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // MENUPAIS_H_INCLUDED
