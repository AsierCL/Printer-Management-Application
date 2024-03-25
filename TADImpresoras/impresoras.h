#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "./estructura.h"

///////////////////////////////////////////////////




/**
 * Amosa unha barra de progreso na saída estándar baseándose nun porcentaxe dado.
 *
 * @param porcentaxe Porcentaxe completado para a barra de progreso.
 */
void barraDeProgreso(int porcentaje);

/**
 * Amosa unha barra de progreso animada.
 */
void mostrarBarra();

/**
 * Lee unha liña do arquivo e convértea nunha estrutura de tipo Impresora.
 *
 * @param linea A liña do arquivo que se vai ler.
 * @param impresora Punteiro á estrutura Impresora onde se almacenarán os datos lidos.
 */
void leerImpresora(char *linea, Impresora* impresora);

/**
 * Lee un arquivo de impresoras e carga os datos nunha lista de impresoras.
 *
 * @param nome_arquivo Nome do arquivo que se vai ler.
 * @param lista_impresoras Punteiro á lista onde se cargarán as impresoras lidas.
 */
void leerArquivo(char* nombre_arquivo, TLISTA* lista_impresoras);

/**
 * Escribe os datos da lista de impresoras nun arquivo.
 *
 * @param nome_arquivo Nome do arquivo onde se van escribir os datos.
 * @param lista_impresoras Lista de impresoras cuxos datos se van escribir no arquivo.
 */
void escribirArquivo(char* nome_arquivo, TLISTA lista_impresoras);

/**
 * Imprime pola saída estándar a lista de impresoras.
 *
 * @param lista_impresoras Lista de impresoras que se vai imprimir.
 */
void printearLista(TLISTA lista_impresoras);

/**
 * Elimina unha impresora da lista de impresoras.
 *
 * @param lista_impresoras Punteiro á lista de impresoras da cal se eliminará unha impresora.
 */
void eliminarImpresora(TLISTA* lista_impresoras);

/**
 * Engade unha nova impresora á lista de impresoras.
 *
 * @param lista_impresoras Punteiro á lista de impresoras á cal se engadirá unha nova impresora.
 */
void engadirImpresora(TLISTA* lista_impresoras);

/**
 * Engade un traballo á cola de impresión dunha impresora específica.
 *
 * @param lista_impresoras Punteiro á lista de impresoras.
 */
void engadirCola(TLISTA* lista_impresoras);

/**
 * Imprime os traballos en espera na cola de impresión dunha impresora específica.
 *
 * @param cola_impresion Punteiro á cola de impresión que se vai imprimir.
 */
void imprimirCola(TCOLA* cola_impresion);

/**
 * Lista os traballos pendentes de impresión para unha impresora específica.
 *
 * @param lista_impresoras Punteiro á lista de impresoras.
 */
void listarTraballosPendentes(TLISTA* lista_impresoras);

/**
 * Elimina un traballo da cola de impresión dunha impresora específica.
 *
 * @param lista_impresoras Punteiro á lista de impresoras.
 */
void eliminarCola(TLISTA* lista_impresoras);

/**
 * Lista as impresoras con menos carga de traballo.
 *
 * @param lista_impresoras Punteiro á lista de impresoras.
 */
void listarImpresorasMenosCarga(TLISTA* lista_impresoras);

/**
 * Amosa o menú de axuda coas opcións dispoñibles.
 */
void amosarAxuda();

#endif /// IMPRESORAS_H