#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdbool.h>

/* predefined */
typedef struct {
    float values[4][4];
} Mat4x4;

typedef struct __matrix_internal Matrix;
struct __matrix_internal {
    int row, col;
    void *priv;
};

typedef struct __matrix_algo MatrixAlgo;
struct __matrix_algo {
    /* operations */
    void (*assign)(Matrix *thiz, Mat4x4);
    bool (*equal)(const Matrix *l, const Matrix *r);
    bool (*mul)(Matrix *dst, const Matrix *l, const Matrix *r);
};

/* Available matrix providers */
extern MatrixAlgo NaiveMatrixProvider;

#endif /* MATRIX_H_ */
