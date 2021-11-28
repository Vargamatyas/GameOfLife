//
// Created by Varga Mátyás on 11/12/21.
//

//
// Created by Varga Mátyás on 10/28/21.
// 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
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



#ifndef GAME_OF_LIFE_ENVIRONMENT_H

#define GAME_OF_LIFE_ENVIRONMENT_H
#ifdef _WIN32

#else
#include <unistd.h>
#endif

typedef struct Matrix{
    int x;
    int y;
    int** table;
    int** temp_table;
} Matrix;



int ** create_table(int x, int y);

void zero_down(Matrix *m);

Matrix* create_matrix(int x, int y);

void show_matrix(Matrix *m);

void cls(Matrix * m);

bool are_tables_equal(Matrix * m);

void copy_table(Matrix *m);

void free_table(int **table, int y);

void delete_matrix(Matrix *m);

void change_cell(Matrix *matrix, int x, int y);

int check_neighbours(int x, int y, Matrix *m);

void take_step(Matrix *m);

void iterate(Matrix *m, int n);
#endif //GAME_OF_LIFE_ENVIRONMENT_H
