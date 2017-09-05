#include <stdio.h>
#include <stdlib.h>

int** pyth(int);

int main() {
    int limit;
    printf("Type positive integer greater than 2 and less then 100000000 : ");
    scanf("%d", &limit);
    if(limit < 2 || limit >= 100000000) {
        printf("input is incorrect.");
        return 0;
    }
    int** result = pyth(limit);
    for(int i = 0; i < limit; ++i) {
        int catet = result[i][0];
        if (catet) printf("%d %d %d\n", catet, result[i][1], result[i][2]);
    }
    return 0;
}

int** pyth(int limit) {
    int** list = (int**) malloc(sizeof(int*) * limit);
    for (int i = 0; i < limit; list[i] = (int*) malloc(sizeof(int*) * 3), ++i) ;
    int hypo = 0;
    int m = 2;
    while (hypo < limit) {
        for (int n = 1; n < m; ++n) {
            hypo = m*m + n*n;
            if(hypo > limit) break;
            list[m][2] = hypo;
            list[m][0] = m*m - n*n;
            list[m][1] = 2*m*n;
        }
        ++m;
    }
    return list;
}

