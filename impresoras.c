#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "lista.h"

#include "estructura.h"


// Proceso e almaceno cada liña (impresora) nun TIPOELEMENTOLISTA
void leerImpresora(char *linea, TIPOELEMENTOLISTA* impresora, int *indice) {
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


    (*indice)++;
}



void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras) {

    // abres o archivo generado por Arch_TXT
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "r");

    //Check
    if (arquivo_impresoras == NULL) {
        perror("Error ao abrir o archivo de entrada");
        exit(1);
    }

    char linea[500];
    int indice = 0;
    TIPOELEMENTOLISTA impresora;

    recuperarElementoLista(lista_impresoras, primeroLista(lista_impresoras), &impresora);

    
    // Leer linea x linea do archivo
    while (fgets(linea, sizeof(linea), arquivo_impresoras) != NULL && indice < 5000) {
        leerImpresora(linea, &impresora, &indice);
    }

    // Cerrar archivo de entrada
    fclose(arquivo_impresoras);

}

void escribirArquivo(char *nombre_arquivo, TLISTA lista_impresoras){
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "w");

    //Check
    if (arquivo_impresoras == NULL) {
        perror("Error ao abrir o archivo de entrada");
        exit(1);
    }


    TIPOELEMENTOLISTA impresora;
    int indice = 0;

    // Escribimos o vector de estructuras no archivo binario
    //fprintf(impresora, sizeof(impresora), indice, arquivo_impresoras);

    // Cerramos archivo binario
    fclose(arquivo_impresoras);

}