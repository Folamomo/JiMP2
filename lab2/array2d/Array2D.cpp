//
// Created by igor on 06.03.18.
//

#include "Array2D.h"

bool CheckSizes(int n_rows, int n_columns);

int **NewArray2D(int n_rows, int n_columns){
    if(CheckSizes(n_rows, n_columns)){
        return nullptr;
    }

    int **topArray = new int*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        topArray[i] = new int[n_columns];
    }
    FillArray2D(n_rows, n_columns, topArray);
    return topArray;
}

void FillArray2D(int n_rows, int n_columns, int **topArray) {
    if(CheckSizes(n_rows, n_columns)){
        return;
    }
    
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_columns; ++j) {
            topArray[i][j]=i*n_columns+j+1;
        }
    }
}

bool CheckSizes(int n_rows, int n_columns) { return n_rows < 1 || n_columns < 1; }

void DeleteArray2D(int **array, int n_rows, int n_columns){
    if(CheckSizes(n_rows, n_columns)){
        return;
    }
    for (int i = 0; i < n_rows; ++i) {
        delete array[i];
    }
    delete array;
}

