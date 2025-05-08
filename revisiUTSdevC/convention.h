#ifndef CONVENTION_H
#define CONVENTION_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define list(S) (S)->list 
#define namaKota(K) (K)->namaKota
#define listWarga(K) (K)->listWarga
#define Nil NULL
typedef char* infotype;

//boolean
#define true 1
#define false 0
typedef int boolean;

#endif