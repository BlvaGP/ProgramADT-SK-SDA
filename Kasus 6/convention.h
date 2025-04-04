#ifndef CONVENTION_H
#define CONVENTION_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define head(l) (l)->head //for queue
#define tail(l) (l)->tail //for queue
#define list(S) (S)->list //for stack
#define namaKota(K) (K)->namaKota
#define listWarga(K) (K)->listWarga
#define Nil NULL

//boolean
#define true 1
#define false 0
typedef int boolean;

#endif