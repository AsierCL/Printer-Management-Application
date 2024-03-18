#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para a función sleep

#include "cola.h"
#include "lista.h"
#include "estructura.h"


void barraDeProgreso(int porcentaxe) {
    const int lonxitudeBarra = 50; // Lonx total da barra de progreso
    int caracteresParaMostrar = porcentaxe * lonxitudeBarra / 100; // Num de caracteres

    printf("["); // Print do inicio da barra
    for (int i = 0; i < lonxitudeBarra; ++i) {
        if (i < caracteresParaMostrar)
            printf("="); // Parte completada
        else
            printf(" "); // Parte sin completar
    }
    printf("] %d%%\r", porcentaxe); // Print final da barra
    fflush(stdout); // Limpa o buffer de salida para escribir o seguinte porcentaxe da barra
}

void mostrarBarra(){
    for (int i = 0; i <= 100; ++i) {
        barraDeProgreso(i); // Funcion debuxar barra
        usleep(10000); // Pausa en microsegundos (1/1,000,000 segundos)
        if(i>100)exit(1);
    }
    printf("\n"); 
}



void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras) {

    // Abro o arquivo
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "r");
    
    // Fago un bucle infinito, e pároo cando no fscanf se chegue a EOF
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
    // Empezo dende o primeiro elemento, e vou printeando e pasando ao seguinte ca función do TAD ata que chegue a NULL
    TPOSICION posicion_aux = primeroLista(lista_impresoras);
    while (siguienteLista(lista_impresoras, posicion_aux) != NULL){
        TIPOELEMENTOLISTA impresora_aux;
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        printf("%s %s %s %s\n", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
        posicion_aux = siguienteLista(lista_impresoras, posicion_aux);
    }
}


void eliminarImpresora(TLISTA* lista_impresoras){
    // Declaro as variables necesarias
    char impresora_eliminar[32];
    TPOSICION posicion_elimiar;
    TIPOELEMENTOLISTA impresora_aux;
    int check = 0;
    posicion_elimiar = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_elimiar, &impresora_aux);

    scanf(" %s",impresora_eliminar);

    while ((siguienteLista(lista_impresoras, posicion_elimiar) != NULL) && (check == 0)){
        recuperarElementoLista(lista_impresoras, posicion_elimiar, &impresora_aux);
        
        if(strcmp(impresora_aux.nombre, impresora_eliminar) == 0){
            check = 1;
            suprimirElementoLista(lista_impresoras, posicion_elimiar);
            return;
        }
        else{
            posicion_elimiar = siguienteLista(lista_impresoras, posicion_elimiar);
        }
    }
    printf("Non se atopou a impresora %s",impresora_eliminar);
    sleep(1);
}

void añadirImpresora(TLISTA* lista_impresoras){
    TIPOELEMENTOLISTA impresora_aux;
    printf("Introduce a nova impresora (nombre|marca|modelo|ubicación):\n");
    scanf("%s %s %s %s", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
    insertarElementoLista(lista_impresoras, finLista(*lista_impresoras), impresora_aux);
}
