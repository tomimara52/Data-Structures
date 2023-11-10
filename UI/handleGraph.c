#include "handlers.h"
#include "../Graphs/Normal-Graphs/graph.h"

/*  PRINT INFO OF GRAPH (size and current state)  */
void printGraphInfo(MyGraph* g){
    printf("\n\t\tCURRENT EDGES: ");
    printGraph(g);
    printf("\t\tSIZE: %d\n", graphSize(g));
    fflush(stdout);
}

/*  PRINT GRAPH MENU  */
void printGraphMenu(MyGraph* g){
        printf("\n- MAIN MENU -> GRAPH MENU\n");
        printGraphInfo(g);
        printf("\n\t\tAdd edge: 'A'\n"
                        "\t\tRemove edge: 'R'\n"
                        "\t\tRemove Vertex: 'V'\n"
                        "\t\tCheck if Edge exists: 'E'\n"
                        "\t\tGet current Vertices in the graph: 'X'\n"
                        "\t\tGet Connections of a vertex: 'C'\n"
                        "\t\tPrint Graph: 'P'\n"
                        "\t\tExport to Graphium: 'G'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleGraph(){
    MyGraph* g = newGraph();
    char quit = 0, choice = 0;
    int in0 = 0, in1 = 0;
    while (!quit){

        clearConsole();
        printGraphMenu(g);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':
                printf("\n\t\t\tEdge to add \"v1, v2\": ");
                fscanf(stdin, " %d, %d", &in0, &in1);

                // ADD THE EDGE
                addEdge(g, in0, in1);
                break;
            
            case 'R':
                printf("\n\t\t\tEdge to remove \"v1, v2\": ");
                fscanf(stdin, " %d, %d", &in0, &in1);

                // REMOVE THE CHOSEN EDGE
                removeEdge(g, in0, in1);
                break;

            case 'V':
                printf("\n\t\t\tSelect Vertex to remove: ");
                fscanf(stdin, " %d", &in0);

                removeVertex(g, in0);
                break;

            case 'E':
                printf("\n\t\t\tEdge to look for \"v1, v2\": ");
                fscanf(stdin, " %d, %d", &in0, &in1);

                // CHECK IF EXISTS
                printf("\n\t\t\tEdge [%d, %d] %s exist in the graph.", in0, in1, isEdge(g, in0, in1) ? "DOES" : "DOES NOT");
                break;
            
            case 'X':
                printf("\n\t\t\tCurrent Vertices in the graph: ");

                int *vtcs = vertices(g, &in0);
                for (int i = 0; i<in0; ++i)
                    printf(" %d", vtcs[i]);
                free(vtcs);

                printf("\n");
                break;
            
            case 'C':
                printf("\n\t\t\tSelect a Vertex: ");
                fscanf(stdin, " %d", &in0);

                printf("\n\t\t\tVertices connected to %d are: ", in0);

                int *arr = connections(g, in0, &in1); // Load array of connections.
                for (int i = 0; i<in1;++i)
                    printf("%d ", arr[i]);
                free(arr);

                printf("\n");
                break;

            case 'P':
                printGraphInfo(g);
                break;

            case 'G':
                FILE *fpath = fopen("../graphium/saved-graphs/importedGraph", "w");
                
                if (!fpath){
                    printf("\nUnable to create file.\n"
                                    "\tMake sure to follow the instructions on "
                                    "how to use graphium from the README.md file\n");
                    break;
                }

                // Load all vertices of the graph into verts. Save return size in &in0.
                int* verts = vertices(g, &in0);

                for (int i = 0; i<in0; ++i){
                    fprintf(fpath, "%d| ", verts[i]);
                    // Load array of all vertices connected to verts[i]. Retsize in &in1.
                    int* cons = connections(g, verts[i], &in1);
                    for (int j = 0; j<in1; ++j)
                        fprintf(fpath, "%d", cons[j]);
                    free(cons);
                    fprintf(fpath, "\n");
                }
                free(verts);

                printf("\nSuccesfully exported to graphium.\n"
                                "Exit and run graphium as instructred "
                                "in the README to visualize it.\n");
                fflush(fpath);
                fclose(fpath);
                break;

            case 'e':
                quit = 1;
                freeGraph(g);
                fflush(stdout);
                break;

            default:
                break;
        }

        if (!quit){
            printf("\n\t\t\tContinue? Y/n -> ");
            fscanf(stdin, " %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeGraph(g);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    printf("\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}