#include "handlers.h"
#include "../Trees/Binary-Tree/binaryTree.h"

/*  PRINT INFO OF TREE (size and current state)  */
void printTreeInfo(MyTree* t){
    fprintf(stdout, "\n\t\tCURRENT TREE (INORDER TRAVERSAL): ");
    printTree(t, INORDER);
    fprintf(stdout, "\t\tSIZE: %d\n", treeSize(t));
    fflush(stdout);
}

/*  PRINT TREE MENU  */
void printTreeMenu(MyTree* t){
        fprintf(stdout, "\n- MAIN MENU -> TREE MENU\n");
        printTreeInfo(t);
        fprintf(stdout, "\n\t\tAdd Node: 'A'\n"
                        "\t\tRemove Node (all instances): 'R'\n"
                        "\t\tCheck if node exists: 'C'\n"
                        "\t\tPrint in a special order traversal: 'P'\n"
                        "\t\tPrint Tree: 'p'\n"
                        "\t\tVisualize Tree: 'v'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleTree(){
    MyTree* t = newTree();
    char quit = 0, choice = 0;
    int in0 = 0;
    while (!quit){

        clearConsole();
        printTreeMenu(t);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':
                fprintf(stdout, "\n\t\t\tSelect node to add: ");
                fscanf(stdin, " %d", &in0);

                // ADD THE NEW NODE
                addNode(t, in0);
                break;
            
            case 'R':
                fprintf(stdout, "\n\t\t\tSelect node to remove: ");
                fscanf(stdin, " %d", &in0);

                // REMOVE ALL INSTANCES OF THE CHOSEN NODE
                removeNode(t, in0);
                break;

            case 'C':
                fprintf(stdout, "\n\t\t\tSelect node to look for: ");
                fscanf(stdin, " %d", &in0);

                // CHECK IF CHOSEN NODE EXISTS
                fprintf(stdout, "\n\t\t\tThe node %d %s exist in the Tree.\n", in0, isNode(t, in0) ? "DOES": "DOES NOT");
                break;

            case 'P':
                fprintf(stdout, "\n"
                                "\t\t\tPREORDER TRAVERSAL -> '0'\n"
                                "\t\t\tINORDER TRAVERSAL -> '1'\n"
                                "\t\t\tPOSTORDER TRAVERSAL -> '2'\n"
                                "\n\t\t\tSelect an order: ");
    
                fscanf(stdin, " %d", &in0); // Save order selection in &in0.
                
                fprintf(stdout, "\n\t\t\t%sORDER TRAVERSAL IS: ", in0 == 0 ? "PRE" : in0 == 1 ? "IN" : "POST");
                printTree(t, in0);
                break;

            case 'p':
                printTreeInfo(t);
                break;

            case 'v':
                visualizeTree(t, 0, 0);
                break;

            case 'e':
                quit = 1;
                freeTree(t);
    
                fflush(stdout);
                break;

            default:
                break;
        }

        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fscanf(stdin, " %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeTree(t);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    fprintf(stdout, "\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}
