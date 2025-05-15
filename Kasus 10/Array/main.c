#include "array10.h"

int main() {
    Isi_Tree P;

    Create_tree(P, jml_maks);
    inputBinaryTree(P);

    printf("Inorder Traversal of the Belva Tree:\n");
    InOrder(P);
    printf("\n\n");

    printf("Converting 'JTK Politeknik Negeri Bandung' to Belva code:\n");
    char inputString[50] = "JTK Politeknik Negeri Bandung";
    char dummyBuffer[50][50];
    convertStringToCode(P, inputString, dummyBuffer, 0);
    printf("\n");

    printf("Converting code 'LLLLL LPPL PL PPPPP LLLLP LPLL L LLLLL' to string:\n");
    convertCodeToString(P);
    printf("\n");

    printf("Reading from input.txt, converting to Belva code, and saving to out.txt:\n");
    readText(P);

    return 0;
}