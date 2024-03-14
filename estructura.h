#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include "cola.h"

typedef struct {
    char nombre[32];
    char marca[32];
    char modelo[32];
    char ubicacion[32];
    TCOLA cola_impresion;
} Impresora;

#endif 