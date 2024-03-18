#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "estructura.h"

void mostrarBarra();
void barraDeProgreso(int porcentaje);

// Proceso e almaceno cada liña (impresora) nun TIPOELEMENTOLISTA
void leerImpresora(char *linea, Impresora* impresora);
void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras);
void escribirArquivo(char* nombre_arquivo, TLISTA lista_impresoras);
void printearLista(TLISTA lista_impresoras);
void eliminarImpresora(TLISTA* lista_impresoras);
void añadirImpresora(TLISTA* lista_impresoras);

#endif /// IMPRESORAS_H