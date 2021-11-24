//
// Created by Varga Mátyás on 11/20/21.
//
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void save_Matrix(Matrix* m, char *name){
    FILE *f;
    f = fopen(name ,"w");
    if(f!=NULL)f = fopen(name ,"a");

    fprintf(f, "%d\n", m->y);
    fprintf(f, "%d\n", m->x);

    for (int y = 0; y < m->y; ++y) {
        for (int x = 0; x < m->x; ++x) {
            fprintf(f,"%d", m->table[y][x]+1);
            /*+1 mert ha pl 000 lenne akkor a visszaolvasas nem mukodne mert
             * sscanf%ld 000-ra 0-t adna vissza*/
        }
        fprintf(f,"\n");
    }
    fclose(f);
    printf("A file mentve %s neven", name);
}

static void separate(long int n, int y, Matrix *m){
    //n is row what we want to break up
    //y is the current row
    for(int x=m->x; 0<=x; --x){
        int value = n%10;
        m->table[y][x] = value - 1;
        n /= 10;
    }
}

Matrix *load_Matrix(char* name){
    FILE* f;
    f = fopen(name, "r");
    //Matrix *returnable = (Matrix*) malloc(1 * sizeof(Matrix *));
//    Matrix *returnable = create_matrix(1, 1);

    char line[200];
    if(f!=NULL){
//        fgets(line, 20, f);
//        line[strcspn(line, "\n")] = 0;

        int x, y;
        fgets(line, 4, f);
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%d",&y);

        fgets(line, 4, f);
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%d",&x);
        Matrix *returnable = create_matrix(x, y);
        for(int k=0; k<returnable->y;++k){
            fgets(line,200,f);
            line[strcspn(line, "\n")] = 0;
            long int n;

            sscanf(line,"%ld", &n);
            //printf("%ld\n", n);
            separate(n, k, returnable);
        }
        return returnable;
    }

    else perror("a file megnyitasa sikertelen");
    fclose(f);
    return NULL;
}