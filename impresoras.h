#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "estructura.h"


// Proceso e almaceno cada liña (impresora) nun TIPOELEMENTOLISTA
void leerImpresora(char *linea, Impresora* impresora, int *indice);
void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras);
void escribirArquivo(char* nombre_arquivo, TLISTA lista_impresoras);

#endif /// IMPRESORAS_H