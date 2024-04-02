#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para a función sleep

#include "../TADs/cola.h"
#include "../TADs/lista.h"
#include "./estructura.h"


    /* Secuencias de escape ANSI:
    "\x1b[31m"  --  Vermello
    "\x1b[32m"  --  Verde
    "\x1b[0m"   --  Color pred.
    */



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
    if (arquivo_impresoras == NULL){
        perror("\x1b[31mErro ao abrir o arquivo de impresoras\x1b[0m\n");
        exit(1);
    }

    // Fago un bucle infinito, e pároo cando no fscanf se chegue a EOF
    while(1){
        // Declaro as variables necesarias para insertar a impresora
        TIPOELEMENTOLISTA impresora_insertar;
        crearCola(&impresora_insertar.cola_impresion);
        int i = 0;

        // Declaro as variables para comprobar que non hai impresoras repetidas
        TPOSICION posicion_aux;
        TIPOELEMENTOLISTA impresora_aux;
        
        i = fscanf(arquivo_impresoras, "%31s %31s %31s %31s", impresora_insertar.nombre, impresora_insertar.marca, impresora_insertar.modelo, impresora_insertar.ubicacion);
        
        if (i==EOF) {
            return; 
            // Sae do bucle
        }

        if (i != 4) {
            // Non atopou os 4 campos
            printf("\x1b[31mErro ao leer o arquivo %s\x1b[0m\n", nombre_arquivo);
            exit(1);
        }

        // Verificamos que non haxa duas impresoras co mesmo nome
        posicion_aux = primeroLista(*lista_impresoras);
        while ((siguienteLista(*lista_impresoras, posicion_aux) != NULL)){
            recuperarElementoLista(*lista_impresoras, posicion_aux, &impresora_aux);
            
            // Se atopa a impresora:
            if(strcmp(impresora_aux.nombre, impresora_insertar.nombre) == 0){
                printf("\x1b[31m\n\nO arquivo ten duas impresoras co mesmo nome\x1b[0m\n");
                printf("\x1b[31m\nNome repetido: %s\x1b[0m\n", impresora_aux.nombre);
                sleep(4);
                exit(1);
            }
            else{
                posicion_aux = siguienteLista(*lista_impresoras, posicion_aux);
            }
        }
        insertarElementoLista(lista_impresoras, finLista(*lista_impresoras), impresora_insertar);
    }
    // Cerramos o arquivo
    fclose(arquivo_impresoras);
}


void escribirArquivo(char* nombre_arquivo, TLISTA* lista_impresoras){
    
    // Abro o arquivo
    FILE *arquivo_impresoras = fopen(nombre_arquivo, "w");
        if (arquivo_impresoras == NULL){
        perror("\x1b[31mErro ao abrir o arquivo para gardar os datos\x1b[0m\n");
        exit(1);
    }

    // Declaro as variables necesarias
    TPOSICION posicion_aux = primeroLista(lista_impresoras);

    while (siguienteLista(lista_impresoras, posicion_aux) != NULL){
        TIPOELEMENTOLISTA impresora_aux;
        recuperarElementoLista(lista_impresoras, posicion_aux, &impresora_aux);
        
        if (fprintf(arquivo_impresoras, "%s %s %s %s\n", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion) < 0) {
            printf("\x1b[31mErro ao leer o arquivo %s\x1b[0m\n", nombre_arquivo);
            // Toma medidas adicionales según sea necesario, como cerrar el archivo y finalizar la ejecución
        }

        posicion_aux = siguienteLista(lista_impresoras, posicion_aux);
    }

    // Cerro o arquivo
    fclose(arquivo_impresoras);
}


void printearLista(TLISTA lista_impresoras){
    // Printeo o seguinte elemento comezando dende o principio ata que chegue a NULL
    
    // Declaro as variables necesarias
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
    TPOSICION posicion_eliminar;
    TIPOELEMENTOLISTA impresora_aux;
    posicion_eliminar = primeroLista(*lista_impresoras);
    // Check
    if(posicion_eliminar==NULL){
        perror("\x1b[31mErro ao eliminar impresoras\nErro na lista\x1b[0m\n");
        return;
    }
    recuperarElementoLista(lista_impresoras, posicion_eliminar, &impresora_aux);

    // Salida por pantalla
    printf("\n\nEscriba a impresora que quere eliminar:\n");
    printf("(Únicamente escriba o nome (primera columna))\n\n");
    printearLista(*lista_impresoras);
    printf("\n");
    scanf(" %31s",impresora_eliminar);

    // Iteramos elemento por elemento ata atopar a coincidencia
    while ((siguienteLista(lista_impresoras, posicion_eliminar) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_eliminar, &impresora_aux);
        
        if(strcmp(impresora_aux.nombre, impresora_eliminar) == 0){ // Coincidencia de nomes
            printf("\x1b[32mImpresora eliminada:\n%s %s %s %s\x1b[0m\n", impresora_aux.nombre, impresora_aux.marca, impresora_aux.modelo, impresora_aux.ubicacion);
            destruirCola(&impresora_aux.cola_impresion);
            suprimirElementoLista(lista_impresoras, posicion_eliminar);
            sleep(2);
            return;
        }
        else{
            posicion_eliminar = siguienteLista(lista_impresoras, posicion_eliminar);
        }
    }

    // Caso erro
    printf("\x1b[31mNon se atopou a impresora %s\x1b[0m\n",impresora_eliminar);
    sleep(2);
}


void engadirImpresora(TLISTA* lista_impresoras){
    
    // Declaro as variables necesarias
    TIPOELEMENTOLISTA impresora_insertar;
    crearCola(&impresora_insertar.cola_impresion);
    int i = 0;

    // Declaro as variables necesarias para o check do nombre repetido
    TPOSICION posicion_impresora_modificada;
    TIPOELEMENTOLISTA impresora_aux;
    posicion_impresora_modificada = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);


    printf("Introduce a nova impresora (nombre|marca|modelo|ubicación):\n");

    // Caso error
    if (scanf("%31s %31s %31s %31s", impresora_insertar.nombre, impresora_insertar.marca, impresora_insertar.modelo, impresora_insertar.ubicacion) != 4) {
        printf("\x1b[31mError: Los datos ingresados exceden el tamaño máximo permitido\x1b[0m\n");
        while (getchar() != '\n');
        return;
    }

    // Iteramos elemento por elemento
    while ((siguienteLista(lista_impresoras, posicion_impresora_modificada) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);
        
        // Se atopa a impresora:
        if(strcmp(impresora_aux.nombre, impresora_insertar.nombre) == 0){
            printf("\x1b[31mXa existe unha impresora con ese nome\x1b[0m\n");
            sleep(4);
            return;
        }
        else{
            posicion_impresora_modificada = siguienteLista(lista_impresoras, posicion_impresora_modificada);
        }
    }

    // Se non hai ese elemento na lista, procedese a:
    insertarElementoLista(lista_impresoras, finLista(*lista_impresoras), impresora_insertar);

    printf("\x1b[32m\nEngadeuse con éxito a impresora %s\x1b[0m\n",impresora_insertar.nombre);
    printf("\nLista actualizada:\n");
    printearLista(*lista_impresoras);
    sleep(4);
}


void engadirCola(TLISTA* lista_impresoras){
    
    // Declaro as variables necesarias
    char impresora_modificada[32];
    TPOSICION posicion_impresora_modificada;
    TIPOELEMENTOLISTA impresora_aux;
    TIPOELEMENTOCOLA id;
    posicion_impresora_modificada = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);

    // Salida por terminal
    printearLista(*lista_impresoras);
    printf("\nIntroduce o nome da impresora a que se lle quere engadir traballo:\n");
    scanf(" %31s",impresora_modificada);

    // Comprobo unha por unha que coincida
    while ((siguienteLista(lista_impresoras, posicion_impresora_modificada) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);
        
        // Se atopa a impresora:
        if(strcmp(impresora_aux.nombre, impresora_modificada) == 0){
            printf("\nIntroduce o id do traballo que queres engadir:\n");
            scanf("%d",&id);
            anadirElementoCola(&impresora_aux.cola_impresion, id);
            return;
        }
        else{
            posicion_impresora_modificada = siguienteLista(lista_impresoras, posicion_impresora_modificada);
        }
    }

    // Non atopa a impresora
    printf("\x1b[31mNon se atopou a impresora %s\x1b[0m\n",impresora_modificada);
    sleep(2);
}



void imprimirCola(TCOLA* cola_impresion){
    // Se cola==vacia
    if ((tamanoCola(*cola_impresion)==0)||esColaVacia(*cola_impresion)){
        printf("\x1b[31m\nNon hai traballos pendentes\x1b[0m\n");
        return;
    }
    
    // Consultar elemento por elemento
    /* Creamos un elemento auxiliar
    *  consultamos o elemento da cola correspondente,
    *  e asignámolo ao novo elemento.
    *  Imprimímolo por pantalla, borrámolo do inicio da cola, e engadímolo ao final.
    *  Facendo esto o numero de veces do tamano da cola, a lista queda igual que ao comezo. */
    for(int i=0;i<tamanoCola(*cola_impresion);i++){
        TIPOELEMENTOCOLA elemento_aux;
        consultarPrimerElementoCola(*cola_impresion, &elemento_aux);
        printf("\nO id do elemento %d é: %d\n", i+1, elemento_aux);
        suprimirElementoCola(cola_impresion);
        anadirElementoCola(cola_impresion, elemento_aux);
    }
}


void listarTraballosPendentes(TLISTA* lista_impresoras){
    
    // Declaro as variables necesarias
    char nombre_impresora_aux[32];
    TPOSICION posicion_impresora_aux;
    TIPOELEMENTOLISTA impresora_aux;
    posicion_impresora_aux = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_impresora_aux, &impresora_aux);
    
    // Salida por pantalla
    printf("\nLista de impresoras:\n");
    printearLista(*lista_impresoras);
    printf("\nIntroduce o nome da impresora a que se lle quere consultar a cola de impresión:\n");
    scanf(" %31s",nombre_impresora_aux);
    
    // Iteramos elemento por elemento
    while ((siguienteLista(lista_impresoras, posicion_impresora_aux) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_aux, &impresora_aux);
        
        // Se atopa a impresora:
        if(strcmp(impresora_aux.nombre, nombre_impresora_aux) == 0){
            imprimirCola(&impresora_aux.cola_impresion);
            fflush(stdout);
            sleep(4);
            return;
        }
        else{
            posicion_impresora_aux = siguienteLista(lista_impresoras, posicion_impresora_aux);
        }
    }
    // Non atopa a impresora
    printf("\x1b[31mNon se atopou a impresora %s\x1b[0m\n",nombre_impresora_aux);
    sleep(2);
}


void eliminarCola(TLISTA* lista_impresoras){
    
    // Declaro as variables necesarias
    char impresora_modificada[32];
    TPOSICION posicion_impresora_modificada;
    TIPOELEMENTOLISTA impresora_aux;
    posicion_impresora_modificada = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);

    // Salida por terminal
    printearLista(*lista_impresoras);
    printf("Introduce o nome da impresora na que se quere imprimir un traballo:\n");
    scanf(" %31s",impresora_modificada);

    // Comprobo unha por unha que coincida
    while ((siguienteLista(lista_impresoras, posicion_impresora_modificada) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_modificada, &impresora_aux);
        
        // Se atopa a impresora:
        if(strcmp(impresora_aux.nombre, impresora_modificada) == 0){
            TIPOELEMENTOCOLA telementocola_aux = NULL;
            
            // Se está vacia:
            if (esColaVacia(impresora_aux.cola_impresion)){
                printf("\x1b[31m\nNon hai ningún elemento para imprimir\x1b[0m\n");
                sleep(2);
                return;
            }
            
            consultarPrimerElementoCola(impresora_aux.cola_impresion, &telementocola_aux);
            // Check
            if (telementocola_aux==NULL){
                printf("\x1b[31m\nNon hai ningún elemento para imprimir\x1b[0m\n");
                sleep(2);
                return;
            }
            // Saída por pantalla
            printf("Imprimindo o arquivo %d\n", telementocola_aux);
            suprimirElementoCola(&impresora_aux.cola_impresion);
            printf("Cola de impresion actualizada");
            imprimirCola(&impresora_aux.cola_impresion);
            sleep(2);
            return;
        }
        else{
            posicion_impresora_modificada = siguienteLista(lista_impresoras, posicion_impresora_modificada);
        }
    }

    // Non atopa a impresora
    printf("\x1b[31mNon se atopou a impresora %s\x1b[0m\n",impresora_modificada);
    sleep(2);
}

void listarImpresorasMenosCarga(TLISTA* lista_impresoras){
    // Declaro as variables necesarias
    int tamano_min;
    int num_impresoras_tamano_minimo = 0;
    TPOSICION posicion_impresora_aux;
    TIPOELEMENTOLISTA impresora_aux;
    posicion_impresora_aux = primeroLista(*lista_impresoras);
    recuperarElementoLista(lista_impresoras, posicion_impresora_aux, &impresora_aux);
    tamano_min = tamanoCola(impresora_aux.cola_impresion);

    // Atopamos o num mínimo de tamaño
    while ((siguienteLista(lista_impresoras, posicion_impresora_aux) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_aux, &impresora_aux);
        
        if(tamanoCola(impresora_aux.cola_impresion) == tamano_min){
            num_impresoras_tamano_minimo++;
        }
        if(tamanoCola(impresora_aux.cola_impresion) < tamano_min){
            num_impresoras_tamano_minimo = 0;
            tamano_min = tamanoCola(impresora_aux.cola_impresion);
        }
        
        posicion_impresora_aux = siguienteLista(lista_impresoras, posicion_impresora_aux);
    }
    printf("\nHai %d impresoras con carga minima\n",num_impresoras_tamano_minimo);

    // Rewind ao principio
    posicion_impresora_aux = primeroLista(*lista_impresoras); 
    
    // Buscamos as impresoras que teñan o tamaño mínimo
    while ((siguienteLista(lista_impresoras, posicion_impresora_aux) != NULL)){
        recuperarElementoLista(lista_impresoras, posicion_impresora_aux, &impresora_aux);
        // Se ten o tamaño mínimo, imprímese
        if(tamanoCola(impresora_aux.cola_impresion) == tamano_min){
            printf("%s\n",impresora_aux.nombre);
        }
        
        posicion_impresora_aux = siguienteLista(lista_impresoras, posicion_impresora_aux);
    }
    fflush(stdout);
    sleep(5);
}


// Menu de axuda
void amosarAxuda(){
    printf("\na) Eliminar impresora: Elimina unha impresora da lista de impresoras dispoñibles.\n");
    printf("\nb) Engadir impresora: Engade unha impresora á lista de impresoras dispoñibles.\n");
    printf("\nc) Enviar traballo: Envia un traballo de impresión a unha impresora específica.\n");
    printf("\nd) Cola de impresión: Amosa a cola de traballos de impresión en espera.\n");
    printf("\ne) Imprimir traballo: Imprime un traballo dunha impresora específica.\n");
    printf("\nf) Buscar impresoras con pouca carga: Amosa as impresoras con baixa carga de traballo.\n");
    printf("\ng) Axuda: Amosa este menú de axuda.\n");
    printf("\ns) Sair: Sae do programa.\n");
    printf("\n (Enter para sair)\n");
    printf("\n--------------------------------------------------------------\n");
    getchar();
    getchar();
    system("clear");
}
