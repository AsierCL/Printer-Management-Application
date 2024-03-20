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
void engadirImpresora(TLISTA* lista_impresoras);
void engadirCola(TLISTA* lista_impresoras);
void imprimirCola(TCOLA* cola_impresion);
void listarTraballosPendentes(TLISTA* lista_impresoras);
void eliminarCola(TLISTA* lista_impresoras);
void mostrarAxuda();

#endif /// IMPRESORAS_H