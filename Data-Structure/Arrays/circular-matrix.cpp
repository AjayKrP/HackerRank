//#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int mat[4][4] = {{1, 2, 5, 4},
                     {8, 9, 7, 1},
                      {9, 7, 6, 3},
                      {2, 3, 5, 8}};

    int m = 4, n = 4, k = 0, l = 0;
    while (k < m && l < n) {
        for (int j = l; j < n; ++j) {
            cout << mat[k][j] << "\t";
        }
        k++;

        for (int i = k; i < m; ++i) {
            cout << mat[i][n-1] << "\t";
        }
        n--;

        if(k < m) {
            for (int i = n-1; i >= 1; --i) {
                cout << mat[m-1][i] << "\t";
            }
            m--;
        }
        if (l < n) {
            for (int i = m-1; i >= k; --i) {
                cout << mat[i][l] << "\t";
            }
            l++;
        }

    }
}
