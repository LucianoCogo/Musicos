#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void backupMusicos(){
    FILE* pMusico = fopen("musicos.dat", "rb");
    FILE* pMusicoBKP = fopen("musicos.bkp", "wb");
    if (pMusico == NULL || pMusicoBKP == NULL) {
        cout << "Error al abrir los archivos." << endl;
        if (pMusico != NULL) fclose(pMusico);
        if (pMusicoBKP != NULL) fclose(pMusicoBKP);
        system("pause");
        return;
    }

    Musico obj;

    while (fread(&obj, sizeof(Musico), 1, pMusico) == 1) {
        fwrite(&obj, sizeof(Musico), 1, pMusicoBKP);
    }
    cout << "Copia de seguridad creada exitosamente." << endl;
    system("pause");
    fclose(pMusico);
    fclose(pMusicoBKP);
}

void backupGeneros(){
    FILE* pGenero = fopen("generos.dat", "rb");
    FILE* pGeneroBKP = fopen("generos.bkp", "wb");

    if (pGenero == NULL || pGeneroBKP == NULL) {
        cout << "Error al abrir los archivos." << endl;
        if (pGenero != NULL) fclose(pGenero);
        if (pGeneroBKP != NULL) fclose(pGeneroBKP);
        system("pause");
        return;
    }

    Genero obj;

    while (fread(&obj, sizeof(Genero), 1, pGenero) == 1) {
        fwrite(&obj, sizeof(Genero), 1, pGeneroBKP);
    }

    cout << "Copia de seguridad creada exitosamente." << endl;
    system("pause");
    fclose(pGenero);
    fclose(pGeneroBKP);
}

void backupInstrumentos(){
    FILE* pInstrumento = fopen("instrumentos.dat", "rb");
    FILE* pInstrumentoBKP = fopen("instrumentos.bkp", "wb");

    if (pInstrumento == NULL || pInstrumentoBKP == NULL) {
        cout << "Error al abrir los archivos." << endl;
        if (pInstrumento != NULL) fclose(pInstrumento);
        if (pInstrumentoBKP != NULL) fclose(pInstrumentoBKP);
        system("pause");
        return;
    }

    Instrumento obj;

    while (fread(&obj, sizeof(Instrumento), 1, pInstrumento) == 1) {
        fwrite(&obj, sizeof(Instrumento), 1, pInstrumentoBKP);
    }

    cout << "Copia de seguridad creada exitosamente." << endl;
    system("pause");
    fclose(pInstrumento);
    fclose(pInstrumentoBKP);
}

void backupPaises(){
    FILE* pPais = fopen("Paises.dat", "rb");
    FILE* pPaisBKP = fopen("Paises.bkp", "wb");

    if (pPais == NULL || pPaisBKP == NULL) {
        cout << "Error al abrir los archivos." << endl;
        if (pPais != NULL) fclose(pPais);
        if (pPaisBKP != NULL) fclose(pPaisBKP);
        system("pause");
        return;
    }

    Pais obj;

    while (fread(&obj, sizeof(Pais), 1, pPais) == 1) {
        fwrite(&obj, sizeof(Pais), 1, pPaisBKP);
    }

    cout << "Copia de seguridad creada exitosamente." << endl;
    system("pause");
    fclose(pPais);
    fclose(pPaisBKP);
}

void restaurarMusicos(){
    FILE* pMusicoBKP = fopen("musicos.bkp", "rb");
    FILE* pMusico = fopen("musicos.dat", "wb");
    if (pMusicoBKP == NULL || pMusico == NULL) {
        cout << "Error al abrir los archivos." << endl;
        system("pause");
        return;
    }

    Musico obj;

    while (fread(&obj, sizeof(Musico), 1, pMusicoBKP) == 1) {
        fwrite(&obj, sizeof(Musico), 1, pMusico);
    }
    cout << "Archivo restaurado." << endl;
    system("pause");
    fclose(pMusico);
    fclose(pMusicoBKP);
}

void restaurarGeneros(){
    FILE* pGeneroBKP = fopen("generos.bkp", "rb");
    FILE* pGenero = fopen("generos.dat", "wb");
    if (pGenero == NULL || pGeneroBKP == NULL){
        cout << "Error al abrir los archivos." << endl;
        system("pause");
        return;
    }

    Genero obj;

    while (fread(&obj, sizeof(Genero), 1, pGeneroBKP) == 1) {
        fwrite(&obj, sizeof(Genero), 1, pGenero);
    }

    cout << "Archivo restaurado." << endl;
    system("pause");
    fclose(pGenero);
    fclose(pGeneroBKP);
}

void datosInicio(){
    FILE* pGeneroI = fopen("generos.conf", "rb");
    FILE* pMusicoI = fopen("musicos.conf", "rb");
    FILE* pInstrumentoI = fopen("instrumentos.conf", "rb");
    FILE* pPaisI = fopen("paises.conf", "rb");

    FILE* pGenero = fopen("generos.dat", "wb");
    FILE* pMusico = fopen("musicos.dat", "wb");
    FILE* pInstrumento = fopen("instrumentos.dat", "wb");
    FILE* pPais = fopen("paises.dat", "wb");

    if (pGenero == NULL || pMusico == NULL || pInstrumento == NULL || pPais == NULL || pGeneroI == NULL || pMusicoI == NULL || pInstrumentoI == NULL || pPaisI == NULL){
        cout << "Error al abrir los archivos." << endl;
        system("pause");
        if (pGenero != NULL) fclose(pGenero);
        if (pMusico != NULL) fclose(pMusico);
        if (pInstrumento != NULL) fclose(pInstrumento);
        if (pPais != NULL) fclose(pPais);
        if (pGeneroI != NULL) fclose(pGeneroI);
        if (pMusicoI != NULL) fclose(pMusicoI);
        if (pInstrumentoI != NULL) fclose(pInstrumentoI);
        if (pPaisI != NULL) fclose(pPaisI);
        return;
    }

    Genero obj1;
    Musico obj2;
    Instrumento obj3;
    Pais obj4;

    while (fread(&obj1, sizeof(Genero), 1, pGeneroI) == 1) {
        fwrite(&obj1, sizeof(Genero), 1, pGenero);
    }
    while (fread(&obj2, sizeof(Musico), 1, pMusicoI) == 1) {
        fwrite(&obj2, sizeof(Musico), 1, pMusico);
    }
    while (fread(&obj3, sizeof(Instrumento), 1, pInstrumentoI) == 1) {
        fwrite(&obj3, sizeof(Instrumento), 1, pInstrumento);
    }
    while (fread(&obj4, sizeof(Pais), 1, pPaisI) == 1) {
        fwrite(&obj4, sizeof(Pais), 1, pPais);
    }

    cout << "Los archivos han sido restaurados a su estado original." << endl;
    system("pause");

    fclose(pGenero);
    fclose(pMusico);
    fclose(pInstrumento);
    fclose(pPais);
    fclose(pGeneroI);
    fclose(pMusicoI);
    fclose(pInstrumentoI);
    fclose(pPaisI);
}

#endif // CONFIGURACION_H_INCLUDED
