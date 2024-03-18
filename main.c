#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

#include "lista.h"
#include "cola.h"
#include "impresoras.h"

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
        printf("\nDebes indicar un archivo de impresoras\n");
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
        printf("\n--------------------------------------------------------------\n");
        printf("\na) Eliminar impresora     d) Cola de impresión\n");
        printf("\nb) Añadir impresora       e) Imprimir traballo\n");
        printf("\nc) Enviar traballo        f) Buscar impresoras con pouca carga\n ");
        printf("\n");
        printf("\ng) Ayuda                  s) Sair\n");
        printf("\n--------------------------------------------------------------\n");
        printf("\nOpción: ");
        scanf(" %c", &opcion);
        
        
        switch (opcion) {
            case 'a': 
                system("clear");
                printf("-------------------------");
                printf("\n| a) Eliminar impresora |\n");
                printf("-------------------------");
                printf("\n\nEscriba a impresora que queere eliminar:\n");
                printf("(Únicamente escriba o nome (primera columna))\n\n");
                fflush(stdout);
                sleep(1);
                printearLista(lista_impresoras);
                eliminarImpresora(&lista_impresoras);
                system("clear");
                break;

            case 'b':
                system("clear");
                printf("-------------------------");
                printf("\n| a) Añadir impresora |\n");
                printf("-------------------------\n");
                añadirImpresora(&lista_impresoras);
                printf("\nLista actualizada:\n");
                printearLista(lista_impresoras);
                break;

            case 'c':


                break;

            case 'd':


                break;

            case 'e':


                break;

            case 'f':


                break;

            case 'g':


                break;

            case 's':
                printf("Gardando os datos...\n");
                escribirArquivo(argv[1], lista_impresoras);
                mostrarBarra();
                printf("\nSalindo do programa...\n");
                break;

            default:
                printf("\n A opción é incorrecta \n");
                break;
        }
    } while (opcion != 's');
    return(EXIT_SUCCESS);
}