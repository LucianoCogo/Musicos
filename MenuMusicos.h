#ifndef MENUMUSICOS_H_INCLUDED
#define MENUMUSICOS_H_INCLUDED

void menuMusicos(){
    ArchivoMusico obj(ARCHIVO_MUSICOS);
    int opc;
    while(true){
        system("cls");
        cout << "MENU MUSICOS:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Agregar musico." << endl;
        cout << "2 - Listar musicos por DNI." << endl;
        cout << "3 - Listar todos los musicos." << endl;
        cout << "4 - Modificar la fecha de inscripcion." << endl;
        cout << "5 - Dar de baja un musico." << endl;
        cout << "------------------------" << endl;
        cout << "0 - Volver al menu principal." << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: obj.agregarMusico();
                    break;
            case 2: obj.buscarPorDNI();
                    break;
            case 3: obj.mostrarListadoMusicos();
                    break;
            case 4: obj.modificarFechaInscripcion();
                    break;
            case 5: obj.bajaLogicaMusico();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // MENUMUSICOS_H_INCLUDED
