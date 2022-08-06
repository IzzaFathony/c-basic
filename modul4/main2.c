#include <stdio.h>

int main(void) {
    int array2[2][2];
    int array3[3][3];
    int i, j, k, big, small;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Array index [%d][%d] = ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", array2[i][j]);
        }
        printf("\n");
    }

    big = array2[0][0];
    small = array2[0][0];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (big < array2[i][j]) {
                big = array2[i][j];
            }
            if (small > array2[i][j]) {
                small = array2[i][j];
            }
        }
    }

    printf("Smallest : %d", small);
    printf("\tBiggest : %d\n", big);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Array index [%d][%d] = ", i, j);
            scanf("%d", &array3[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", array3[i][j]);
        }
        printf("\n");
    }

    big = array3[0][0];
    small = array3[0][0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (big < array3[i][j]) {
                big = array3[i][j];
            }
            if (small > array3[i][j]) {
                small = array3[i][j];
            }
        }
    }

    printf("Smallest : %d", small);
    printf("\tBiggest : %d\n", big);

    return 0;
}