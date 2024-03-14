#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
    
    // Declaro as variables globales
    char opcion;
    TLISTA lista_impresoras;
    crearLista(&lista_impresoras);
    leerArquivo(argv[1], &lista_impresoras);

    // BUCLE PARA A INTERFAZ GRÁFICA //
    do{
        printf("\n--------------------------------------------------------------\n");
        printf("\na) Eliminar impresora     d) Cola de impresión\n");
        printf("\nb) Añadir impresora       e) Imprimir programa\n");
        printf("\nc) Enviar traballo        f) Buscar impresoras con pouca carga\n ");
        printf("\ng) Ayuda                  s) Sair\n");
        printf("\n--------------------------------------------------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion);
        
        ///system("clear");
        
        switch (opcion) {
            case 'a': 
                printf("\na) Eliminar impresora\n");

                break;

            case 'b':


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
                printf("Saliendo del programa...\n");
                escribirArquivo(argv[1], lista_impresoras);

                break;

            default:
                printf("La opción es incorrecta");
                break;
        }
    } while (opcion != 's');
    return(EXIT_SUCCESS);
}