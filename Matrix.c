//
// Created by Varga Mátyás on 11/12/21.
//

#include "Matrix.h"

void cls(Matrix * m){
    for(int i=0; i<m->y + 20; ++i) printf("\n");
}

void show_matrix(Matrix *m){
    cls(m);
    int x = m->x,  y = m->y;
    for(int i=0; i<y; ++i){

        for(int k=0; k<x; ++k){
            if(m->table[i][k] == 1) printf("X");
            else printf("-");
        }
        printf("\n");
    }

}

int ** create_table(int x, int y){
    int **table = (int **) malloc(y * sizeof(int *));
    for(int i=0; i<y; ++i){
        int *row = (int *) malloc(x * sizeof(int));
        table[i] = row;

    }
    return table;
}

void zero_down(Matrix *m){
    for(int y=0; y<m->y; ++y){
        for(int x=0; x<m->x; ++x){
            m->table[y][x] = 0;
            m->temp_table[y][x] = 0;
        }
    }
}

Matrix* create_matrix(int x, int y){
    Matrix *new_M = (Matrix *) malloc(1 * sizeof(Matrix));
    new_M->x = x;
    new_M->y = y;
    new_M->table = create_table(x, y);

    new_M->temp_table = create_table(x, y);
    zero_down(new_M);
    copy_table(new_M);
    return new_M;
}

bool are_tables_equal(Matrix * m){
    for(int i =0; i<m->y; ++i){
        for(int k =0; k<m->x; ++k){
            if(m->table[i][k] != m->temp_table[i][k]) return false;
        }
    }
    return true;
}

void copy_table(Matrix *m){

    for(int i=0; i <m->y; ++i){
        for(int k=0; k<m->x; ++k){
            m->temp_table[i][k] = m->table[i][k];
        }
    }
    printf("\n");
}

void free_table(int **table, int y){

    for(int i=0; i<y; ++i){
        free(table[i]);
    }
    free(table);
}

void delete_matrix(Matrix *m){
    free_table(m->table, m->y);
    free_table(m->temp_table, m->y);
    free(m);
}

void change_cell(Matrix *matrix, int x, int y){
    int m_x = matrix->x;
    int m_y = matrix->y;

    if(x>=0 && y>=0 && m_x>x && m_y>y){

        if(matrix->table[y][x] == 0){
            matrix->table[y][x] = 1;

        }else matrix->table[y][x] = 0;
    }

    else ;

}

int check_neighbours(int x, int y, Matrix *m){

    int alive_neighbours = 0;
    if(m->temp_table[y][x] == 1) --alive_neighbours;

    for(int i = y - 1 ; i < y+2; ++i){
        for(int k = x - 1; k < x+2; ++k){
            if(0<=i && 0<=k && k < m->x && i <m->y) {
                if (m->temp_table[i][k] == 1 ) ++alive_neighbours;
            }
        }
    }
    return alive_neighbours;
}

void take_step(Matrix *m){
    // generate the next generation of the environment
    printf("\n");

    copy_table(m);
    for(int y=0; y <m->y; ++y){
        for(int x=0; x<m->x; ++x){
            int neighbours_alive = check_neighbours(x, y, m);

            if(neighbours_alive == 3 || (neighbours_alive == 2 && m->temp_table[y][x] == 1) )  m->table[y][x] = 1;
            else m->table[y][x] = 0;
        }
    }
    show_matrix(m);
}

void iterate(Matrix *m, int n){
    //play the game of life step n-times on the given matrix
    for(int i=0; i<n; ++i){
        take_step(m);
        cls(m);
        show_matrix(m);
        usleep(900000);
        if(are_tables_equal(m) == true) break;
    }
}
