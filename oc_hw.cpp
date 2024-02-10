#include <iostream>
#include <omp.h>

using namespace std;

#define N 3
#define M 3
#define K 3

int mat1[N][M] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int mat2[M][K] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int result[N][K];

int main() {
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}