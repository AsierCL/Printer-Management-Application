#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

///#include "lista.h"
///#include "cola.h"


////////////////////
////    Main    ////
////////////////////

int main(int argc, char** argv){
    char opcion;

    /// BUCLE PARA A INTERFAZ GRÁFICA ///
    do{
        printf("\n-------------------------------------------------------\n");
        printf("\na) Eliminar impresora\n");
        printf("\nb) Añadir impresora\n");
        printf("\nc) Enviar traballo\n ");
        printf("\nd) Cola de impresión\n");
        printf("\ne) Imprimir programa\n");
        printf("\nf) Buscar impresoras con pouca carga\n");
        printf("\ns) Sair\n");
        printf("\n-------------------------------------------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion); //cuidado con el espacio
        
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


            case 's':
                printf("Saliendo del programa...\n");


                break;

            default:
                printf("La opción es incorrecta");
                break;
        }
    } while (opcion != 's');
    return(EXIT_SUCCESS);
}