#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para a función sleep

#include "cola.h"
#include "lista.h"
#include "estructura.h"


void barraDeProgreso(int porcentaje) {
    const int longitudBarra = 50; // Longitud total de la barra de progreso
    int caracteresParaMostrar = porcentaje * longitudBarra / 100; // Número de caracteres a mostrar

    printf("["); // Imprimir el inicio de la barra de progreso
    for (int i = 0; i < longitudBarra; ++i) {
        if (i < caracteresParaMostrar)
            printf("="); // Mostrar parte de la barra completada
        else
            printf(" "); // Mostrar parte de la barra restante
    }
    printf("] %d%%\r", porcentaje); // Mostrar el porcentaje y regresar al inicio de la línea
    fflush(stdout); // Limpiar el búfer de salida para imprimir inmediatamente
}

void mostrarBarra(){
    for (int i = 0; i <= 100; ++i) {
        barraDeProgreso(i); // Mostrar la barra de progreso con el porcentaje actual
        // Simulación de algún trabajo
        usleep(10000); // Pausa de 1 segundo
        if(i>100)exit(1);
    }
    printf("\n"); 
}



void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras) {

    // Abro o arquivo
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "r");
    while(1){
        TIPOELEMENTOLISTA impresora_aux;
        int i = 0;
        i = fscanf(arquivo_impresoras, "%s %s %s %s", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        if (i==EOF) return;
        insertarElementoLista(lista_impresoras, finLista(*lista_impresoras), impresora_aux);
    }
}


void escribirArquivo(char* nombre_arquivo, TLISTA* lista_impresoras){
    
    // Abro o arquivo
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "w");
    
    TPOSICION posicion_aux = primeroLista(lista_impresoras);
    while (siguienteLista(lista_impresoras, posicion_aux) != NULL){
        TIPOELEMENTOLISTA impresora_aux;
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        fprintf(arquivo_impresoras,"%s %s %s %s\n", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        posicion_aux = siguienteLista(lista_impresoras, posicion_aux);
    }
}

void printearLista(TLISTA lista_impresoras){
    TPOSICION posicion_aux = primeroLista(lista_impresoras);
    while (siguienteLista(lista_impresoras, posicion_aux) != NULL){
        TIPOELEMENTOLISTA impresora_aux;
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        printf("%s %s %s %s\n", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        posicion_aux = siguienteLista(lista_impresoras, posicion_aux);
    }
}