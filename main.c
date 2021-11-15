#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include "Matrix.h"
#include "debugmalloc.h"



int main() {
    bool run = true;
    Matrix* actual_matrix = NULL;
    //glider for testing
    actual_matrix = create_matrix(10, 10);
    change_cell(actual_matrix, 4, 3);
    change_cell(actual_matrix, 4, 1);
    change_cell(actual_matrix, 4, 2);
    change_cell(actual_matrix, 2, 2);
    change_cell(actual_matrix, 3, 3);



    while (run){
        char command[100+1];
        int x =0, y=0, n=0;

        printf("Please type some commands, for help type: 'help'\n");
        fgets(command, 100, stdin);

        printf("%s", command);
        command[strcspn(command, "\n")] = 0; //from stackoverflow https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input




        if(strcmp(command, "Exit") == 0 || strcmp(command, "exit") ==0) run = false;

        else if(sscanf(command, "createMatrix %d %d", &x, &y) == 2) {
            if(actual_matrix != NULL) delete_matrix(actual_matrix);

            actual_matrix = create_matrix(x, y);
            show_matrix(actual_matrix);
        }
        else if(sscanf(command, "auto %d", &n) == 1){
            printf("meeegy");
            if(actual_matrix == NULL){
                //error_handling(1);
            }
            else {
                iterate(actual_matrix, n); }
        }
        else if(strcmp(command, "next")==0){

            take_step(actual_matrix);
            //show_matrix(actual_matrix);
        }
        else if(sscanf(command, "change %d %d", &x, &y) == 2){
            if(actual_matrix == NULL){}//error_handling(1);
            else change_cell(actual_matrix, x, y);
        }
        else if(strcmp(command, "show Matrix")==0){
            show_matrix(actual_matrix);
        }
    }




    return 0;
}
