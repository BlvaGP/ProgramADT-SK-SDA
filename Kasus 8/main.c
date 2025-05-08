#include "case8.h"

int main() {
    Isi_Tree T;
    int Jml_Node;
    int input;
	
    printf("Masukkan jumlah node (maks %d): ", jml_maks);
    scanf("%d", &Jml_Node);
    
    Create_tree(T, Jml_Node);
    addData(&T);
    
    while (1) {
        printf("=== NON BINARY TREE ===\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &input);
        
        switch (input) {
        	case 1:
        		printf("\nTraversal PreOrder: ");
        		PreOrder(T);
        		break;
        	case 2:
        		printf("\nTraversal InOrder: ");
    			InOrder(T);
        		break;
        	case 3:
        		printf("\nTraversal PostOrder: ");
    			PostOrder(T);
        		break;
        	case 4:
        		printf("\nTraversal LevelOrder: ");
    			Level_order(T, Jml_Node);
        		break;
        	case 5:
        		PrintTree(T);
        		break;
        	case 6:
        		searchNode(&T);
        		break;
        	case 7:
        		printf("Jumlah daun: %d\n", nbDaun(T));
        		break;
        	case 8:
        		searchNodeLevel(&T);
        		break;
        	case 9:
        		printf("Kedalaman tree: %d\n", Depth(T));
        		break;
        	case 10:
        		compareNode(&T);
        		break;
        	case 11:
        		exit(0);
        		break;
		}
    }
    return 0;
}