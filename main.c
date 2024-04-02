#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

#include "TADs/lista.h"
#include "TADs/cola.h"
#include "TADImpresoras/impresoras.h"

//////////////////////////////////////////////
//  Funcións en camelCase: funcionCrear     //
//  Variables en snake_case: variable_crear //
//////////////////////////////////////////////



////////////////////
////    Main    ////
////////////////////

int main(int argc, char** argv){
    // Gestión de error en caso de non incluir un archivo txt de impresoras.
    if (argc!=2){
        printf("\x1b[31m\nDebes indicar un archivo de impresoras\x1b[0m\n");
        printf("\nEjemplo de uso: ./programa archivo.txt\n");
        printf("\nSalindo...\n");
        exit(1);
    }

    // Declaro as variables globales
    char opcion;
    TLISTA lista_impresoras;
    crearLista(&lista_impresoras);
    leerArquivo(argv[1], &lista_impresoras);

    // BUCLE PARA A INTERFAZ GRÁFICA //
    do{
        system("clear");
        printf("\n--------------------------------------------------------------\n");
        printf("\na) Eliminar impresora     d) Traballos pendentes\n");
        printf("\nb) Engadir impresora      e) Imprimir traballo\n");
        printf("\nc) Enviar traballo        f) Impresoras con pouca carga\n ");
        printf("\n");
        printf("\ng) Axuda                  s) Sair\n");
        printf("\n--------------------------------------------------------------\n");
        printf("\nOpción: ");
        scanf(" %c", &opcion);
        
        // Entramos no switch
        switch (opcion) {
            case 'a': 
                system("clear");
                printf("-------------------------");
                printf("\n| a) Eliminar impresora |\n");
                printf("-------------------------\n");
                eliminarImpresora(&lista_impresoras);
                system("clear");
                break;

            case 'b':
                system("clear");
                printf("------------------------");
                printf("\n| b) Engadir impresora |\n");
                printf("------------------------\n");
                engadirImpresora(&lista_impresoras);
                system("clear");
                break;

            case 'c':
                system("clear");
                printf("----------------------");
                printf("\n| c) Enviar traballo |\n");
                printf("----------------------\n");
                engadirCola(&lista_impresoras);
                system("clear");
                break;

            case 'd':
                system("clear");
                printf("--------------------------");
                printf("\n| d) Traballos pendentes |\n");
                printf("--------------------------\n");
                listarTraballosPendentes(&lista_impresoras);
                system("clear");
                break;

            case 'e':
                system("clear");
                printf("------------------------");
                printf("\n| e) Imprimir traballo |\n");
                printf("------------------------\n");
                eliminarCola(&lista_impresoras);
                system("clear");
                break;

            case 'f':
                system("clear");
                printf("---------------------------------");
                printf("\n| f) Impresoras con pouca carga |\n");
                printf("---------------------------------\n");
                listarImpresorasMenosCarga(&lista_impresoras);
                system("clear");
                break;

            case 'g':
                system("clear");
                printf("------------");
                printf("\n| g) Axuda |\n");
                printf("------------\n");
                amosarAxuda();
                break;

            case 's':
                printf("Gardando os datos...\n");
                escribirArquivo(argv[1], lista_impresoras);
                mostrarBarra();
                free(lista_impresoras);
                printf("\nSaíndo do programa...\n");
                break;

            default:
                printf("\x1b[31m\nOpción incorrecta\x1b[0m\n");
                sleep(2);
                break;
        }
        while (getchar() != '\n');
    } while (opcion != 's');
    return(EXIT_SUCCESS);
}