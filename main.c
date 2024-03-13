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
    
    
    ///////////////////////////////////////////
    ///        Comprobacions varias         ///
    TLISTA Lista_impresoras;
    crearLista(&Lista_impresoras);
    TIPOELEMENTOLISTA Printer1;
    TIPOELEMENTOLISTA Printer2;
    TIPOELEMENTOLISTA Printer3;
    
    Printer1.Numero_prueba = 4;
    Printer2.Numero_prueba = 6;

    insertarElementoLista(&Lista_impresoras, primeroLista(Lista_impresoras), Printer1);
    insertarElementoLista(&Lista_impresoras, siguienteLista(Lista_impresoras, primeroLista(Lista_impresoras)), Printer2);
    recuperarElementoLista(Lista_impresoras, primeroLista(Lista_impresoras), &Printer3);
    printf("%d", esListaVacia(Lista_impresoras));
    printf("%d",Printer3.Numero_prueba);
    ///        Comprobacions varias         ///
    ///////////////////////////////////////////


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