#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void menuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout << "CONFIGURACION:" << endl;
        cout << "------------------------" << endl;
        cout << "1 - Copia de seguridad del archivo musicos." << endl;
        cout << "2 - Copia de seguridad del archivo generos." << endl;
        cout << "3 - Restaurar el archivo de musicos." << endl;
        cout << "4 - Restaurar el archivo de generos." << endl;
        cout << "5 - Establecer datos de inicio." << endl;
        cout << "------------------------" << endl;
        cout << "0 - Volver al menu principal." << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: backupMusicos();
                    break;
            case 2: backupGeneros();
                    break;
            case 3: restaurarMusicos();
                    break;
            case 4: restaurarGeneros();
                    break;
            case 5: datosInicio();
                    break;
            case 0:
                return;
                break;
            }
        system("cls");
    }
    return;
}

#endif // MENUCONFIGURACION_H_INCLUDED
