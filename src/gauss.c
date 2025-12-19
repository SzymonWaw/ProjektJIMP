#include "gauss.h"
#include <math.h>


int eliminate(Matrix *mat, Matrix *b){
    int n = mat->r; 
    int k, i, j;
    int max_row;

    if (mat->r != mat->c || mat->r != b->r) return 1;

    for (k = 0; k < n - 1; k++) {
        
        max_row = k; 
        for (i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
                max_row = i;
            }
        }

        if (max_row != k) {
            double *temp = mat->data[k];
            mat->data[k] = mat->data[max_row];
            mat->data[max_row] = temp;

            double *temp_b = b->data[k];
            b->data[k] = b->data[max_row];
            b->data[max_row] = temp_b;
        }

        if (mat->data[k][k] == 0) return 1;

        for (i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];

            for (j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0;
}

