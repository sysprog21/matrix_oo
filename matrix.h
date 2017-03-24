#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdbool.h>

/* predefined shortcut */
typedef struct { float values[3][3]; } Mat3x3;
typedef struct { float values[4][4]; } Mat4x4;

typedef struct {
    int row, col;
    void *priv;
} Matrix;

typedef struct {
    void (*assign)(Matrix *thiz, Mat4x4);
    bool (*equal)(const Matrix *l, const Matrix *r);
    bool (*mul)(Matrix *dst, const Matrix *l, const Matrix *r);
} MatrixAlgo;

/* Available matrix providers */
extern MatrixAlgo NaiveMatrixProvider;

#endif /* MATRIX_H_ */
