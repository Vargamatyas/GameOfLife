//
// Created by Varga Mátyás on 10/31/21.
//
#include "Matrix.h"

#ifndef GAME_OF_LIFE_FILE_H
#define GAME_OF_LIFE_FILE_H


void save_Matrix(Matrix* m, char *name);

Matrix *load_Matrix(char* name);
#endif //GAME_OF_LIFE_FILE_H
