#include "case8.h"

void addData(Isi_Tree * X) {
    (*X)[1].info = 'A';  
    (*X)[1].ps_fs = 2;   

    (*X)[2].info = 'B';  
    (*X)[2].ps_fs = 4;   
    (*X)[2].ps_nb = 3;   
    (*X)[2].ps_pr = 1;   

    (*X)[3].info = 'C';  
    (*X)[3].ps_fs = 6;   
    (*X)[3].ps_pr = 1;   

    (*X)[4].info = 'D';  
    (*X)[4].ps_nb = 5;   
    (*X)[4].ps_pr = 2;   

    (*X)[5].info = 'E';  
    (*X)[5].ps_fs = 9;   
    (*X)[5].ps_pr = 2;   

    (*X)[6].info = 'F';  
    (*X)[6].ps_nb = 7;   
    (*X)[6].ps_pr = 3;   

    (*X)[7].info = 'G';  
    (*X)[7].ps_nb = 8;   
    (*X)[7].ps_pr = 3;   

    (*X)[8].info = 'H';  
    (*X)[8].ps_pr = 3;   

    (*X)[9].info = 'I';  
    (*X)[9].ps_nb = 10;   
    (*X)[9].ps_pr = 5;   

    (*X)[10].info = 'J'; 
    (*X)[10].ps_pr = 5;   
}

void searchNode(Isi_Tree * P) {
    char node;
    printf("Masukkan info dari node yang ingin: ");
    scanf(" %c", &node);
    
    if (Search(*P, node)) {
        printf("Node %c ditemukan dalam tree.\n", node);
    } else {
        printf("Node %c tidak ditemukan dalam tree.\n", node);
    }
}

void searchNodeLevel(Isi_Tree * P) {
    char node;
    printf("Masukkan info node yang ingin dicari levelnya: ");
    scanf(" %c", &node);
    
    int level = Level(*P, node);
    if (level == -1) {
        printf("Node %c tidak ditemukan dalam tree.\n", node);
    } else {
        printf("Node %c berada pada level %d.\n", node, level);
    }
}

void compareNode(Isi_Tree * P) {
    char node1, node2;
    printf("Masukkan info node pertama: ");
    scanf(" %c", &node1);
    printf("Masukkan info node kedua: ");
    scanf(" %c", &node2);
    
    if (!Search(*P, node1)) {
        printf("Node %c tidak ditemukan dalam tree.\n", node1);
        return;
    }
    if (!Search(*P, node2)) {
        printf("Node %c tidak ditemukan dalam tree.\n", node2);
        return;
    }
    
    char max_node = Max(node1, node2);
    printf("Node dengan nilai terbesar adalah %c.\n", max_node);
}