#include <stdio.h>
#include "formula.h"

int main(void) {
    int pilihan, s, p, l, t, r, V, L;
        printf("1. Volume & Luas Kubus\n");
        printf("2. Volume & Luas Balok\n");
        printf("3. Volume & Luas Bola\n");
        printf("Pilihan Rumus : ");
        scanf("%d", &pilihan);
        printf("---------------------------\n");

    switch(pilihan) {
        case 1:
            printf("Input panjang SISI : ");
            scanf("%d", &s);

            V = VKubus(s);
            printf("Volume Kubus = %d\n", V);
            L = LKubus(s);
            printf("Luas Kubus = %d", L);
            break;
        case 2:
            printf("Input PANJANG : ");
            scanf("%d", &p);
            printf("Input LEBAR : ");
            scanf("%d", &l);
            printf("Input TINGGI : ");
            scanf("%d", &t);
            
            V = VBalok(p, l, t);
            printf("Volume Balok = %d\n", V);
            L = LBalok(p, l, t);
            printf("Luas Balok = %d", L);
            break;
        case 3:
            printf("Input JARI-JARI : ");
            scanf("%d", &r);

            float V = VBola(r);
            printf("Volume Bola = %f\n", V);
            float L = LBola(r);
            printf("Luas Bola = %f", L);
            break;
        default:
            printf("Pilihan yang anda inputkan salah");
    }

    return 0;
}