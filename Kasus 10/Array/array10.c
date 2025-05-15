#include "array10.h"

void inputBinaryTree(Isi_Tree P) {
    P[1].info = ' '; 
    P[1].ps_fs = 2;  
    P[1].ps_nb = 3;  
    P[1].ps_pr = 0;

    P[2].info = 'S';
    P[2].ps_fs = 4;
    P[2].ps_nb = 5;
    P[2].ps_pr = 1;
    
    P[3].info = 'T';
    P[3].ps_fs = 6;
    P[3].ps_nb = 7;
    P[3].ps_pr = 1;

    P[4].info = 'Q';
    P[4].ps_fs = 8;
    P[4].ps_nb = 9;
    P[4].ps_pr = 2;
    
    P[5].info = 'R';
    P[5].ps_fs = 10;
    P[5].ps_nb = 11;
    P[5].ps_pr = 2;
    
    P[6].info = 'U';
    P[6].ps_fs = 12;
    P[6].ps_nb = 13;
    P[6].ps_pr = 3;
    
    P[7].info = 'V';
    P[7].ps_fs = 14;
    P[7].ps_nb = 15;
    P[7].ps_pr = 3;

    P[8].info = 'M';
    P[8].ps_fs = 16;
    P[8].ps_nb = 17;
    P[8].ps_pr = 4;
    
    P[9].info = 'N';
    P[9].ps_fs = 18;
    P[9].ps_nb = 19;
    P[9].ps_pr = 4;
    
    P[10].info = 'O';
    P[10].ps_fs = 20;
    P[10].ps_nb = 21;
    P[10].ps_pr = 5;
    
    P[11].info = 'P';
    P[11].ps_fs = 22;
    P[11].ps_nb = 23;
    P[11].ps_pr = 5;
    
    P[12].info = 'W';
    P[12].ps_fs = 24;
    P[12].ps_nb = 25;
    P[12].ps_pr = 6;
    
    P[13].info = 'X';
    P[13].ps_fs = 26;
    P[13].ps_nb = 27;
    P[13].ps_pr = 6;
    
    P[14].info = 'Y';
    P[14].ps_fs = 28;
    P[14].ps_nb = 29;
    P[14].ps_pr = 7;
    
    P[15].info = 'Z';
    P[15].ps_fs = 30;
    P[15].ps_nb = 31;
    P[15].ps_pr = 7;

    P[16].info = 'E';
    P[16].ps_fs = 32;
    P[16].ps_nb = 33;
    P[16].ps_pr = 8;
    
    P[17].info = 'F';
    P[17].ps_fs = 34;
    P[17].ps_nb = 35;
    P[17].ps_pr = 8;
    
    P[18].info = 'G';
    P[18].ps_pr = 9;
    
    P[19].info = 'H';
    P[19].ps_pr = 9;
    
    P[20].info = 'I';
    P[20].ps_pr = 10;
    
    P[21].info = 'J';
    P[21].ps_pr = 10;
    
    P[22].info = 'K';
    P[22].ps_pr = 11;
    
    P[23].info = 'L';
    P[23].ps_pr = 11;
    
    P[24].info = '1';
    P[24].ps_pr = 12;
    
    P[25].info = '2';
    P[25].ps_pr = 12;
    
    P[26].info = '3';
    P[26].ps_pr = 13;
    
    P[27].info = '4';
    P[27].ps_pr = 13;
    
    P[28].info = '5';
    P[28].ps_pr = 14;
    
    P[29].info = '6';
    P[29].ps_pr = 14;
    
    P[30].info = '7';
    P[30].ps_fs = 60;
    P[30].ps_pr = 15;
    
    P[31].info = '8';
    P[31].ps_fs = 62;
    P[31].ps_nb = 63;
    P[31].ps_pr = 15;

    P[32].info = 'A';
    P[32].ps_pr = 16;
    
    P[33].info = 'B';
    P[33].ps_pr = 16;
    
    P[34].info = 'C';
    P[34].ps_pr = 17;
    
    P[35].info = 'D';
    P[35].ps_pr = 17;
    
    P[60].info = '9';
    P[60].ps_pr = 30;
    
    P[62].info = '0';
    P[62].ps_pr = 31;
    
    P[63].info = ' ';
    P[63].ps_pr = 31;
}

static boolean findPath(Isi_Tree P, address curr, char target, char code[], int *codeIdx) {
    if (curr == 0 || curr > jml_maks) return false;

    if (P[curr].info == target) {
        return true;
    }

    if (P[curr].ps_fs != 0) {
        code[*codeIdx] = 'L';
        (*codeIdx)++;
        if (findPath(P, P[curr].ps_fs, target, code, codeIdx)) {
            return true;
        }
        (*codeIdx)--;
    }

    if (P[curr].ps_nb != 0) {
        code[*codeIdx] = 'P';
        (*codeIdx)++;
        if (findPath(P, P[curr].ps_nb, target, code, codeIdx)) {
            return true;
        }
        (*codeIdx)--;
    }
    return false;
}

void convertStringToCode(Isi_Tree P, char inputString[50], char outputBuffer[50][50], int lineIdx) {
    int i = 0;
    char lineOutput[256] = "";
    
    while (inputString[i] != '\0') {
        char c = toupper(inputString[i]);
        char code[50] = "";
        int codeIdx = 0;

        if (c == ' ') {
            printf("PPPPP ");
            strcat(lineOutput, "PPPPP ");
            i++;
            continue;
        }

        if (findPath(P, 1, c, code, &codeIdx)) {
            code[codeIdx] = '\0';
            printf("%s ", code);
            strcat(lineOutput, code);
            strcat(lineOutput, " ");
        } else {
            printf("NOT_FOUND ");
            strcat(lineOutput, "NOT_FOUND ");
        }
        i++;
    }
    printf("\n");

    if (strlen(lineOutput) > 0 && lineOutput[strlen(lineOutput) - 1] == ' ') {
        lineOutput[strlen(lineOutput) - 1] = '\0';
    }
    strcpy(outputBuffer[lineIdx], lineOutput);
}

void convertCodeToString(Isi_Tree P) {
    char code[] = "LLLLL LPPL PL PPPPP LLLLP LPLL L LLLLL ";
    int i = 0;
    char currCode[10];
    int codeIdx = 0;

    while (code[i] != '\0') {
        if (code[i] == ' ' || code[i + 1] == '\0') {
            if (codeIdx > 0) {
                currCode[codeIdx] = '\0';
                address curr = 1; 
                boolean validPath = true;
                address lastNode = 1;

                for (int j = 0; j < codeIdx && validPath; j++) {
                    if (currCode[j] == 'L') {
                        if (P[curr].ps_fs != 0 && P[curr].ps_fs <= jml_maks) {
                            lastNode = curr; 
                            curr = P[curr].ps_fs; 
                        } else {
                            validPath = false;
                        }
                    } else if (currCode[j] == 'P') {
                        if (P[curr].ps_nb != 0 && P[curr].ps_nb <= jml_maks) {
                            lastNode = curr; 
                            curr = P[curr].ps_nb;
                        } else {
                            validPath = false;
                        }
                    }
                }

                if (validPath && curr != 0 && curr <= jml_maks && P[curr].info != '\0') {
                    printf("%c", P[curr].info);
                } else if (lastNode != 0 && lastNode <= jml_maks && P[lastNode].info != '\0') {
                    printf("%c", P[lastNode].info);
                } else {
                    printf("?");
                }

                codeIdx = 0; 
            }
            if (code[i] == ' ') printf(" ");
        } else {
            currCode[codeIdx++] = code[i];
        }
        i++;
    }
    printf("\n");
}

void saveText(char inputString[50][50], char codeOutput[50][50]) {
    FILE *fp = fopen("out.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open out.txt for writing!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (inputString[i][0] != '\0') {
            fprintf(fp, "%s\n", codeOutput[i]);
        }
    }
    fclose(fp);
}

void readText(Isi_Tree P) {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input.txt!\n");
        return;
    }

    char line[50][50];
    char codeOutput[50][50];
    int lineCount = 0;

    while (fgets(line[lineCount], 50, fp) != NULL && lineCount < 3) {
        line[lineCount][strcspn(line[lineCount], "\n")] = 0;
        printf("Converting: %s\n", line[lineCount]);
        convertStringToCode(P, line[lineCount], codeOutput, lineCount);
        lineCount++;
    }
    fclose(fp);
    saveText(line, codeOutput);
}