#include <stdio.h>
#include <stdbool.h>

//#include "error_handling.h"

#include <string.h>
#include "Matrix.h"
#include "debugmalloc.h"
#include "file.h"


int main(void) {
    bool run = true;
    Matrix* actual_matrix = NULL;
    //glider for testing
//    actual_matrix = create_matrix(50, 20);
//    change_cell(actual_matrix, 4, 3);
//    change_cell(actual_matrix, 4, 1);
//    change_cell(actual_matrix, 4, 2);
//    change_cell(actual_matrix, 2, 2);
//    change_cell(actual_matrix, 3, 3);



    while (run){
        char command[100+1];
        int x =0, y=0, n=0;
        char file_name[100];
        printf("Please type some commands, for help type: 'help'\n");
        fgets(command, 100, stdin);

        printf("%s", command);
        command[strcspn(command, "\n")] = 0; //from stackoverflow https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input

        if(strcmp(command, "Exit") == 0 || strcmp(command, "exit") ==0) {
            if(actual_matrix!=NULL) {
                delete_matrix(actual_matrix);
            }
            run = false;
        }
        else if(strcmp(command, "Help") == 0 || strcmp(command, "help") == 0) {
            printf("parancsok:\n"
                   "Exit - program leallitasa\n"
                   "createMatrix int int - uj Matrix inicializalasa\n"
                   "showMatrix - aktualis Matrix megjelenitese\n"
                   "next - Game of life algoritmus 1db-szor valo futtatasa\n"
                   "auto int - algoritmus iteralasa n-dbszor\n"
                   "save as str - aktualis Matrix mentese a megadott neven\n"
                   "change int  int - aktualis cella allapotanak megvaltoztatasa\n"
                   "deleteMatrix - torli az aktualis matrixot\n");
        }
        else if(sscanf(command, "createMatrix %d %d", &x, &y) == 2) {
            if(actual_matrix != NULL) {
                char y_n;
                printf("Az aktualis Matrix torolve lesz, folytatja?: (y / n)");
                scanf("%c", &y_n);
                if(y_n == 'y') {
                    delete_matrix(actual_matrix);
                    actual_matrix = create_matrix(x, y);
                    show_matrix(actual_matrix);
                    //lehet egy continue jobb lenne
                }
            }
            actual_matrix = create_matrix(x, y);
            show_matrix(actual_matrix);
        }

        else if(sscanf(command, "load %s", file_name) == 1){
            actual_matrix = load_Matrix(file_name);
        }

        else if(actual_matrix != NULL){

            if(sscanf(command, "auto %d", &n) == 1){
                    iterate(actual_matrix, n);
            }
            else if(strcmp(command, "next")==0){
                take_step(actual_matrix);
            }
            else if(sscanf(command, "change %d %d", &x, &y) == 2){
                change_cell(actual_matrix, x, y);
            }
            else if(strcmp(command, "showMatrix")==0){
                show_matrix(actual_matrix);
            }

            else if(sscanf(command, "save as %s", file_name)==1){
                save_Matrix(actual_matrix, file_name);
            }
            else if(strcmp(command, "deleteMatrix")==0){
                delete_matrix(actual_matrix);
                actual_matrix = NULL;
            }

        }
        else perror("utasitas nem felismerheto, vagy nincs matrix inicializalva , segitsegert ird: \"help\"");

    }



    return 0;
}
