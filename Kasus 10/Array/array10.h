#ifndef ARRAY10_H
#define ARRAY10_H

#include "sbtrees.h"

void inputBinaryTree(Isi_Tree P);
void convertStringToCode(Isi_Tree P, char inputString[50], char outputBuffer[50][50], int lineIdx);
void convertCodeToString(Isi_Tree P);
void saveText(char inputString[50][50], char codeOutput[50][50]);
void readText(Isi_Tree P);

#endif