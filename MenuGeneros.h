#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED

void menuGeneros(){
    ArchivoGenero obj(ARCHIVO_GENEROS);
    int opc;
    while(true){
        system("cls");
        cout << "MENU GENEROS:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Agregar genero." << endl;
        cout << "2 - Listar genero por id." << endl;
        cout << "3 - Listar todo." << endl;
        cout << "4 - Modificar anio origen." << endl;
        cout << "5 - Eliminar registro." << endl;
        cout << "------------------------" << endl;
        cout << "0 - Volver al menu principal." << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: obj.agregarGenero();
                    break;
            case 2: obj.buscarPorIdGenero();
                    break;
            case 3: obj.mostrarListadoGeneros();
                    break;
            case 4: obj.modificarAnioGenero();
                    break;
            case 5: obj.bajaLogicaGenero();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // MENUGENEROS_H_INCLUDED
