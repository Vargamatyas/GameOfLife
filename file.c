//
// Created by Varga Mátyás on 11/20/21.
//
#include "Matrix.h"
#include <stdio.h>
#include <string.h>

void save_Matrix(Matrix* m, char *name){
    FILE *f;
    f = fopen(name ,"w");
    if(f!=NULL)f = fopen(name ,"a");

    fprintf(f, "%d\n", m->y);
    fprintf(f, "%d\n", m->x);

    for (int y = 0; y < m->y; ++y) {
        for (int x = 0; x < m->x; ++x) {
            fprintf(f,"%d", m->table[y][x]);

            /*+1 mert ha pl 000 lenne akkor a visszaolvasas nem mukodne mert
             * sscanf%ld 000-ra 0-t adna vissza  */
        }
        fprintf(f,"\n");
    }
    fclose(f);
    printf("A file mentve %s neven\n", name);
}

static int char_to_int(char n){
    return n - '0';
}

static void separate(char * n, int y, Matrix *m){
    //n is row what we want to break up
    //y is the current row
    printf("%s\n", n);
    for(int x=m->x-1; 0<=x ; --x){
        int value = char_to_int(n[x]);

        m->table[y][x] = value;
    }
}

Matrix *load_Matrix(char* name){
    FILE* f;
    f = fopen(name, "r");
    //Matrix *returnable = (Matrix*) malloc(1 * sizeof(Matrix *));
//    Matrix *returnable = create_matrix(1, 1);

    char line[999+1];
    if(f!=NULL){


        int x, y;
        fgets(line, 4, f);
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%d",&y);

        fgets(line, 4, f);
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%d",&x);

        Matrix *returnable = create_matrix(x, y);




        for(int k=0; k<(returnable->y);++k){

            fgets(line, 999+1, f);
            line[strcspn(line, "\n")] = 0;
            //printf("%s", line);
            separate(line, k, returnable);
        }

        printf("Matrix betoltve\n");
        return returnable;
    }

    else perror("Nem letezik ilyen fajl\n");
    fclose(f);
    return NULL;
}