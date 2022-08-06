#include <stdio.h>

int main(void) {
    int Boruto[3] = {30, 35, 99};
    int Sarada[3] = {84, 17, 30};
    int h, i;

    h = 0, i = 0;
    printf("Nilai Boruto\n");
    while (i < 3) {
        h++;
        printf("Nilai ke-%d : %d\n", h, Boruto[i]);
        i++;
    }

    h = 0, i = 0;
    printf("Nilai Sarada\n");
    while (i < 3) {
        h++;
        printf("Nilai ke-%d : %d\n", h, Sarada[i]);
        i++;
    }

    printf("~~~~~~~~\n");

    for (i = 0; i < 3; i++) {
        if (Boruto[i] > Sarada[i]) {
            printf("Result : 1\n");
        } else {
            printf("Result : 0\n");
        }
    }
    
}