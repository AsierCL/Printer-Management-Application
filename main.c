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
    
    ///Declaro as variables globales
    char opcion;
    TLISTA lista_impresoras;

    // Haces lo que necesites con la lista aquí...
    /// BUCLE PARA A INTERFAZ GRÁFICA ///
    do{
        printf("\n--------------------------------------------------------------\n");
        printf("\na) Eliminar impresora     d) Cola de impresión\n");
        printf("\nb) Añadir impresora       e) Imprimir programa\n");
        printf("\nc) Enviar traballo        f) Buscar impresoras con pouca carga\n ");
        printf("\ns) Sair\n");
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