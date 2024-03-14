#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "lista.h"

#include "estructura.h"


// Proceso e almaceno cada liña (impresora) nun TIPOELEMENTOLISTA
void leerImpresora(char *linea, TIPOELEMENTOLISTA* impresora) {
    // Divídese a liña en tokens
    char *token = strtok(linea, " ");


    // Asigno cada token ao seu campo
    strcpy(impresora->nombre, token);
    token = strtok(NULL, " ");
    strcpy(impresora->marca, token);
    token = strtok(NULL, " ");
    strcpy(impresora->modelo, token);
    token = strtok(NULL, " ");
    strcpy(impresora->ubicacion, token);

}



void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras) {

    // Abro o arquivo
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "r");

    //Check
    if (arquivo_impresoras == NULL) {
        perror("Error ao abrir o archivo de entrada");
        exit(1);
    }

    // Declaro todas as variables que vou usar na función
    char linea[128];
    TIPOELEMENTOLISTA impresora_aux;
    TPOSICION posicion_aux;
    posicion_aux = primeroLista(lista_impresoras);
    TIPOELEMENTOLISTA impresora_prueba;
    
    // Para a primeira estructura
    fgets(linea, sizeof(linea), arquivo_impresoras);
    leerImpresora(linea, &impresora_aux);
    modificarElementoLista(&lista_impresoras, posicion_aux,impresora_aux);

    // Leer linea x linea do archivo
    while (fgets(linea, sizeof(linea), arquivo_impresoras) != NULL) {
        printf("%s \n",linea);
        leerImpresora(linea, &impresora_aux);
        insertarElementoLista(lista_impresoras, posicion_aux, impresora_aux);
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_prueba);
        printf("%s", impresora_prueba.nombre);
        posicion_aux = siguienteLista(lista_impresoras,posicion_aux);
    }

    // Libero memoria e cerro archivos
    free (posicion_aux);
    fclose(arquivo_impresoras);
}

void escribirArquivo(char *nombre_arquivo, TLISTA lista_impresoras){

    // Abro o arquivo
    FILE *arquivo_impresoras = fopen("archivo_escritura.txt", "w");

    //Check
    if (arquivo_impresoras == NULL) {
        perror("Error ao abrir o archivo de saida");
        exit(1);
    }

    // Declaro todas as variables que vou usar na función
    TIPOELEMENTOLISTA impresora_aux;
    TPOSICION posicion_aux;
    posicion_aux = primeroLista(lista_impresoras);
    int indice;

    for(indice = 0; indice < 18; indice++){
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        fprintf(arquivo_impresoras, "%s %s %s %s", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        posicion_aux = siguienteLista(lista_impresoras,posicion_aux);
    }

/*     while(siguienteLista(lista_impresoras,posicion_aux)!=NULL){
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        fprintf(arquivo_impresoras, "%s %s %s %s", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        posicion_aux = siguienteLista(lista_impresoras,posicion_aux);
    } */

    // Libero memoria e cerro archivos
    free (posicion_aux);
    fclose(arquivo_impresoras);
}