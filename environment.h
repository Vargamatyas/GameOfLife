//
// Created by Varga Mátyás on 10/28/21.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef GAME_OF_LIFE_ENVIRONMENT_H
#define GAME_OF_LIFE_ENVIRONMENT_H

typedef struct Matrix{
    int x;
    int y;
    int* table;
} Matrix;

void create_matrix(Matrix *matrix, int x, int y){
    matrix->x = x;
    matrix->y = y;
    int *column = malloc(x*y);
    for(int i=0; i<x; ++i){
        int *row = malloc(x);
        column[i] = *row;
    }
    matrix->table = column;
}

void free_matrix(Matrix *matrix){
    int y = matrix->y;
    for(int i=0; i<y; ++i){
        free(&(matrix->table[i)]);
    }
    free(matrix->table);
}

void change_cell(Matrix *matrix, int x, int y){
    int m_x = matrix->x;
    int m_y = matrix->y;
    if(x!<0 && y!<0 && m_x-1<!x && m_y-1<!y){
        int *cell = &(matrix->table[x][y]);
        if(*cell == 0){
            *cell = 1;
        }else *cell = 0;
    }
    else perror("Cell cordinate out of range");
}

#endif //GAME_OF_LIFE_ENVIRONMENT_H
