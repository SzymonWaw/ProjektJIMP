#include "gauss.h"

int eliminate(Matrix *mat, Matrix *b) {
    if (mat->r != mat->c) return 1;
    if (mat->r != b->r)   return 1;

    const int n = mat->r;

    for (int k = 0; k < n - 1; k++) {
        double pivot = mat->data[k][k];

        if (pivot == 0.0) {
            return 1; 
        }

        for (int i = k + 1; i < n; i++) {
            double *currentRow = mat->data[i];
            double *pivotRow = mat->data[k];
            double factor = currentRow[k] / pivot;

            for (int j = k; j < n; j++) {
                currentRow[j] -= factor * pivotRow[j];
            }

            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0;
}