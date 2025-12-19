#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int n = mat->r;
    int i, j;

    // Sprawdzenie poprawności wymiarów
    if (mat->r != mat->c || mat->r != b->r || x->r != b->r) {
        return 2;
    }

    // Pętla idąca od ostatniego wiersza do pierwszego (wstecz)
    for (i = n - 1; i >= 0; i--) {
        double s = 0;

        // Sumujemy już obliczone wartości x (te "pod" aktualnym wierszem)
        for (j = i + 1; j < n; j++) {
            s += mat->data[i][j] * x->data[j][0];
        }

        // Zabezpieczenie przed dzieleniem przez zero na przekątnej
        if (mat->data[i][i] == 0) {
            return 1;
        }

        // Wyliczamy xi: (bi - suma) / Aii
        x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
    }

    return 0;
}


