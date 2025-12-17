#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i, j;
	int n = mat->r;

	if (mat->r != mat->c || mat->r != b->r || mat->r != x->r || x->c != 1 || b->c != 1){
		return 2;
	}
	for (i = n - 1; i >= 0; i--){
		double sum = 0.0;
		for (j = i + 1; j < n; j++){
			sum += mat->data[i][j] * x->data[j][0];
		}
		if (mat->data[i][j] == 0){
			return 1;
		}
		x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][j];
	}
				return 0;
}


